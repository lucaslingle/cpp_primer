/*
In Chapter 15, we'll extend our query system and will need some additional 
members in the ```QueryResult``` class. Add members ```begin``` and ```end``` 
that return additional iterators into the set of line numbers returned by a
given query, and a member named ```get_file``` that returns a ```shared_ptr```
to the file in the ```QueryResult``` object.
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
using std::vector;
using std::string;
using std::map;
using std::set;
using std::runtime_error;
using std::out_of_range;

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
        const string word;
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
