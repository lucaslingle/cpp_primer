/*
Rewrite ```TextQuery``` and ```QueryResult``` classes to use a
```StrBlob``` instead of a ```vector<string>``` to hold the input file.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <memory>
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

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::vector;
using std::string;
using std::initializer_list;
using std::out_of_range;
using std::runtime_error;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::map;
using std::set;
using size_type = vector<string>::size_type;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    public:
        friend class StrBlobPtr;
        friend class ConstStrBlobPtr;

        StrBlob(): data(make_shared<vector<string>>()) { }
        StrBlob(initializer_list<string> il):
            data(make_shared<vector<string>>(il)) { }

        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }

        void push_back(const string &t) { data->push_back(t); }
        void pop_back() { 
            check(0, "pop_back cannot be applied on empty StrBlob");
            data->pop_back();
        }

        string& front() {
            check(0, "front cannot be applied on empty StrBlob");
            return data->front();
        }
        string& back() {
            check(0, "back cannot be applied on empty StrBlob");
            return data->back();
        }

        const string& front() const {
            check(0, "front cannot be applied on empty StrBlob");
            return data->front();
        }
        const string& back() const {
            check(0, "back cannot be applied on empty StrBlob");
            return data->back();
        }

        StrBlobPtr begin();
        StrBlobPtr end();
        ConstStrBlobPtr begin() const;
        ConstStrBlobPtr end() const;
    
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string &msg) const {
            if (i >= data->size())
                throw out_of_range(msg);
        }
};

class StrBlobPtr {
    public: 
        StrBlobPtr(): curr(0) { }
        StrBlobPtr(StrBlob &a, size_type sz = 0):
            wptr(a.data), curr(sz) { }
        string& deref() const;
        StrBlobPtr& incr();
    private:
        shared_ptr<vector<string>> check(size_type, const string&) const;
        weak_ptr<vector<string>> wptr;
        size_type curr;
};

shared_ptr<vector<string>>
StrBlobPtr::check(size_type i, const string& msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

class ConstStrBlobPtr {
    public: 
        ConstStrBlobPtr(): curr(0) { }
        ConstStrBlobPtr(const StrBlob &a, size_type sz = 0):
            wptr(a.data), curr(sz) { }
        const string& deref() const;
        ConstStrBlobPtr& incr();
    private:
        shared_ptr<vector<string>> check(size_type, const string&) const;
        weak_ptr<vector<string>> wptr;
        size_type curr;
};

shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_type i, const string& msg) const {
    const auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound ConstStrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

const string& ConstStrBlobPtr::deref() const {
    const auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() const { return ConstStrBlobPtr(*this, data->size()); }

using VectorType = StrBlob;
using SetType = set<size_type>;
using MapType = map<string, SetType>;

class QueryResult;

class TextQuery {
    public:
        TextQuery(ifstream &infile) {
            size_type lineno = 0;
            string line;
            while (getline(infile, line)) {
                lines.push_back(line);
                istringstream linestream(line);
                string word;
                while (linestream >> word)
                    (*word2idxs)[word].insert(lineno);
                ++lineno;
            }
        }
        QueryResult query(const string &word);
    private:
        StrBlob lines = StrBlob();
        shared_ptr<MapType> word2idxs = make_shared<MapType>();
};

class QueryResult {
    friend void print(ostream&, const QueryResult&);
    public:
        QueryResult(StrBlob v, 
                    shared_ptr<MapType> m, 
                    const string &s): lines(v), word2idxs(m), query(s) { }
    private:
        StrBlob lines;
        shared_ptr<MapType> word2idxs;
        const string query;
};

QueryResult TextQuery::query(const string &word) {
    return QueryResult(this->lines, this->word2idxs, word);
}

void print(ostream& ost, const QueryResult& qr) {
    try {
        SetType linenos = qr.word2idxs->at(qr.query);
        auto beg = qr.lines.begin();
        for (size_type lineno = 0; lineno < qr.lines.size(); ++lineno) {
            if (linenos.find(lineno) != linenos.end())
                ost << lineno << ": " << beg.deref() << endl; 
            beg.incr();
        }
    } catch (const out_of_range& e) {
        ost << "Query string had no matches." << endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        throw runtime_error("bad format. expected: prog.o fname");

    ifstream inp(argv[1]);
    TextQuery tq(inp);
    while (true) {
        cout << "enter word to look for or q to quit: " << endl;
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s));
    }
}
