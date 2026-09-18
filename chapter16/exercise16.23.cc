/*
Predict when the call operator will be executed in your main query program.
If your expectation and what happens differ, be sure you understand why.
*/

// I predicted that they would never be called prior to program end and I was right.
// Makes sense, because there is no point in time at which a delete happens
// prior to program termination. (Type 'q' to end the program gracefully!)

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
using std::to_string;
using std::min;

using VectorType = vector<string>;
using SetType = set<size_t>;
using MapType = map<string, shared_ptr<SetType>>;

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr): os(s) { }
    template <typename T> void operator()(T *p) const {
        os << "deleting smart ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

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
                    linenos.reset(new SetType, DebugDelete());
                linenos->insert(lineno);
            }
            ++lineno;
        }
    }
    QueryResult query(const string &word) const;
private:
    shared_ptr<VectorType> lines{new VectorType(), DebugDelete()};
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
    static shared_ptr<SetType> nodata(new SetType, DebugDelete());
    auto loc = word2idxs.find(word);
    if (loc == word2idxs.end())
        return QueryResult(word, nodata, lines);
    else
        return QueryResult(word, loc->second, lines);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "bad format. expected: " << argv[0] << " fname" << endl;
        return -1;
    }

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
