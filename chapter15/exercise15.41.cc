/*
Reimplement your classes to use built-in pointers to `Query_base` rather than
`shared_ptr`s. Remember that your classes will no longer be able to use
the synthesized copy-control members.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <cstddef>
#include <memory>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
using std::ostream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::size_t;
using std::ifstream;
using std::istringstream;
using std::getline;
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::runtime_error;
using std::out_of_range;
using std::set_intersection;
using std::inserter;

using VectorType = vector<string>;
using SetType = set<size_t>;
using MapType = map<string, shared_ptr<SetType>>;

class QueryResult;

class TextQuery {
public:
    TextQuery(ifstream &infile) {
        size_t lineno = 0;
        string line;
        while (getline(infile, line)) {
            lines->push_back(line);
            istringstream linestream(line);
            string word;
            while (linestream >> word) {
                auto &linenos = word2idxs[word];
                if (!linenos)
                    linenos.reset(new SetType);
                linenos->insert(lineno);
            }
            ++lineno;
        }
    }
    QueryResult query(const string &word) const;
private:
    shared_ptr<VectorType> lines = make_shared<VectorType>();
    MapType word2idxs;
};

class QueryResult {
friend void print(ostream&, const QueryResult&);
public:
    QueryResult(const string &w, shared_ptr<SetType> s, shared_ptr<VectorType> v): 
        word(w), linenos(s), lines(v) { }
    SetType::iterator begin() { return linenos->begin(); }
    SetType::iterator end() { return linenos->end(); }
    shared_ptr<VectorType> get_file() { return lines; }
private:
    string word;
    shared_ptr<SetType> linenos;
    shared_ptr<VectorType> lines;
};

void print(ostream& ost, const QueryResult& qr) {
    for (size_t lineno : *qr.linenos)
        ost << lineno << ": " << (*qr.lines)[lineno] << endl;  
}

QueryResult TextQuery::query(const string &word) const {
    static shared_ptr<SetType> nodata(new SetType);
    auto loc = word2idxs.find(word);
    if (loc == word2idxs.end())
        return QueryResult(word, nodata, lines);
    else
        return QueryResult(word, loc->second, lines);
}

class Query_base {
friend class Query;
protected:
    using line_no = size_t;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

// class Query {
// friend Query operator~(const Query &);
// friend Query operator|(const Query &, const Query &);
// friend Query operator&(const Query &, const Query &);
// public:
//     Query(const std::string &);
//     QueryResult eval(const TextQuery &t) const { return q->eval(t); }
//     std::string rep() const { return q->rep(); }
// private:
//     Query(std::shared_ptr<Query_base> query): q(query) { }
//     std::shared_ptr<Query_base> q;
// };

class Query {
friend Query operator~(const Query &);
friend Query operator|(const Query &, const Query &);
friend Query operator&(const Query &, const Query &);
public:
    Query(const std::string &);
    Query(const Query &rhs): q(rhs.q), refcount(rhs.refcount) {
        if (rhs.refcount)
            ++*refcount;
    }
    Query(Query &&rhs) noexcept : q(rhs.q), refcount(rhs.refcount) {
        rhs.q = nullptr;
        rhs.refcount = nullptr;
    }
    Query& operator=(const Query &rhs) {
        if (this == &rhs)
            return *this;
        if (refcount && --*refcount == 0) {
            delete q;
            delete refcount;
        }
        q = rhs.q;
        refcount = rhs.refcount;
        if (refcount)
            ++*refcount;
        return *this;
    }
    Query& operator=(Query &&rhs) noexcept {
        if (this == &rhs)
            return *this;
        if (refcount && --*refcount == 0) {
            delete q;
            delete refcount;
        }
        q = rhs.q;
        refcount = rhs.refcount;
        rhs.q = nullptr;
        rhs.refcount = nullptr;
        return *this;
    }
    ~Query() {
        if (refcount && --*refcount == 0) {
            delete q;
            delete refcount;
        }
    }
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }
private:
    Query(Query_base *query): q(query), refcount(new size_t(1)) { }
    Query_base *q;
    size_t *refcount;
};

inline std::ostream& operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}

class WordQuery: public Query_base {
friend class Query;
private:
    WordQuery(const std::string &s): query_word(s) { }
    QueryResult eval(const TextQuery &t) const override { return t.query(query_word); }
    std::string rep() const override { return query_word; }
    std::string query_word;
};

inline Query::Query(const std::string &s): q(new WordQuery(s)), refcount(new size_t(1)) { }

class NotQuery: public Query_base {
friend Query operator~(const Query&);
private:
    NotQuery(const Query &q): query(q) { }
    QueryResult eval(const TextQuery&) const override;
    std::string rep() const override { return "~(" + query.rep() + ")"; }
    Query query;
};

inline Query operator~(const Query &operand) {
    // return std::shared_ptr<Query_base>(new NotQuery(operand));
    return Query(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
        lhs(l), rhs(r), opSym(s) { }
    std::string rep() const override {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;
};

class AndQuery: public BinaryQuery {
friend Query operator&(const Query&, const Query&);
private:
    AndQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "&") { }
    QueryResult eval(const TextQuery&) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
    // return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
    return Query(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(
        left.begin(), left.end(),
        right.begin(), right.end(),
        inserter(*ret_lines, ret_lines->begin())
    );
    return QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery: public BinaryQuery {
friend Query operator|(const Query&, const Query&);
private:
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|") { }
    QueryResult eval(const TextQuery&) const override;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
    // return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
    return Query(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "bad format. expected: " << argv[0] << " fname" << endl;
        return -1;
    }

    ifstream inp(argv[1]);
    TextQuery tq(inp);

    Query q = Query("ipsum") & Query("dolor");
    QueryResult qr = q.eval(tq);
    cout << q.rep() << ": " << endl;
    print(cout, qr);

    q = ~Query("ipsum") & Query("dolor");
    qr = q.eval(tq);
    cout << q.rep() << ": " << endl;
    print(cout, qr);

    q = Query("fakeword1") | Query("dolor");
    qr = q.eval(tq);
    cout << q.rep() << ": " << endl;
    print(cout, qr);

    q = Query("ipsum") | Query("fakeword2");
    qr = q.eval(tq);
    cout << q.rep() << ": " << endl;
    print(cout, qr);

    q = Query("fakeword1") | Query("fakeword2");
    qr = q.eval(tq);
    cout << q.rep() << ": " << endl;
    print(cout, qr);

    return 0;
}
