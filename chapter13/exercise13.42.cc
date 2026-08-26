/*
Text your `StrVec` class by using it in place of the `vector<string>`
used in your TextQuery and QueryResult classes (p. 484).
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <utility>
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::ifstream;
using std::istringstream;
using std::getline;
using std::shared_ptr;
using std::make_shared;
using std::allocator;
using std::uninitialized_copy;
using std::string;
using std::map;
using std::set;
using std::runtime_error;
using std::out_of_range;
using std::pair;


class StrVec {
    public:
        StrVec(): 
            elements(nullptr), first_free(nullptr), cap(nullptr) { }
        StrVec(const StrVec &);
        StrVec& operator=(const StrVec &);
        ~StrVec();
        void push_back(const string &);
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements; }
        string *begin() const { return elements; }
        string *end() const { return first_free; }
        void reserve(size_t);
        void resize(size_t, const string &s = string());
        string& operator[](size_t);
    private:
        static allocator<string> alloc;
        void chk_n_alloc() {
            if (size() == capacity())
                reallocate();
        }
        pair<string*, string*> alloc_n_copy(const string *, const string *);
        void free();
        void reallocate();
        string *elements;
        string *first_free;
        string *cap;
};

allocator<string> StrVec::alloc;

void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> 
StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &sv) {
    auto data = alloc_n_copy(sv.begin(), sv.end());
    elements = data.first;
    first_free = data.second;
    cap = data.second;
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    reserve(newcapacity);
}

void StrVec::reserve(size_t n) {
    if (n <= capacity())
        return;
    auto newcapacity = n;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::resize(size_t n, const string &s) {
    if (n > size()) {
        reserve(n);
        for (size_t i = size(); i != n; ++i)
            alloc.construct(first_free++, s);
    } else {
        while (first_free != elements + n)
            alloc.destroy(--first_free);
    }
}

string& StrVec::operator[](size_t ix) {
    return elements[ix];
}

using VectorType = StrVec;
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
        QueryResult query(const string &word);
    private:
        shared_ptr<VectorType> lines = make_shared<VectorType>();
        MapType word2idxs;
};

class QueryResult {
    friend void print(ostream&, const QueryResult&);
    public:
        QueryResult(shared_ptr<VectorType> v, 
                    shared_ptr<SetType> s, 
                    const string &w): lines(v), linenos(s), word(w) { }
        SetType::iterator begin() { return linenos->begin(); }
        SetType::iterator end() { return linenos->end(); }
        shared_ptr<VectorType> get_file() { return this->lines; }
    private:
        shared_ptr<VectorType> lines;
        shared_ptr<SetType> linenos;
        string word;
};

QueryResult TextQuery::query(const string &word) {
    static shared_ptr<SetType> nodata(new SetType);
    auto loc = (this->word2idxs).find(word);
    if (loc == this->word2idxs.end())
        return QueryResult(this->lines, nodata, word);
    else
        return QueryResult(this->lines, loc->second, word);
}

void print(ostream& ost, const QueryResult& qr) {
    for (size_t lineno : *qr.linenos)
        ost << lineno << ": " << (*qr.lines)[lineno] << endl;  
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
