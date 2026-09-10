/*
Put print statements in the constructors and `rep` members
and run your code to check your answers to (a) and (b) from exercise 15.34.
*/

#include <iostream>
#include <string>
#include <memory>

class Query_base {
    friend class Query;
protected:
    // using line_no = TextQuery::line_no;
    Query_base() {
        std::cout << "Query_base constructor, default" << std::endl;
    }
    virtual ~Query_base() = default;
private:
    // virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
public:
    Query(const std::string &);
    // QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { 
        std::cout << "Query::rep()" << std::endl;
        return q->rep(); 
    }
private:
    Query(std::shared_ptr<Query_base> query): q(query) { 
        std::cout << "Query constructor, pointer-based" << std::endl;
    }
    std::shared_ptr<Query_base> q;
};

inline std::ostream& operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}

class WordQuery: public Query_base {
    friend class Query;
    WordQuery(const std::string &s): query_word(s) { 
        std::cout << "WordQuery constructor, string-based" << std::endl;
    }
    // QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    std::string rep() const override { 
        std::cout << "WordQuery::rep()" << std::endl;
        return query_word; 
    }
    std::string query_word;
};

inline Query::Query(const std::string &s): q(new WordQuery(s)) { 
    std::cout << "Query constructor, string-based" << std::endl;
}

class NotQuery: public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query &q): query(q) { 
        std::cout << "NotQuery constructor, query-based" << std::endl;
    }
    std::string rep() const override { 
        std::cout << "NotQuery::rep()" << std::endl;
        return "~(" + query.rep() + ")"; 
    }
    // QueryResult eval(const TextQuery&) const;
    Query query;
};

inline Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
        lhs(l), rhs(r), opSym(s) { 
            std::cout << "BinaryQuery constructor" << std::endl;
        }
    std::string rep() const override {
        std::cout << "BinaryQuery::rep()" << std::endl;
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;
};

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "&") { 
            std::cout << "AndQuery constructor" << std::endl;
        }
    // QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|") { 
            std::cout << "OrQuery constructor" << std::endl;
        }
    // QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

int main() {
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << "--------------" << std::endl;
    std::cout << q;
    return 0;
}
