/*
Do you think the ```TextQuery``` and ```QueryResult``` classes need to define
their own version of the copy-control members? If so, why? If not, why not?
Implement whichever copy-control operations you think these classes require.
*/

// My original thought was to say no copies or assigns are required, so delete
// the copy constructor and the copy-assign operator. 
//
// The flaw is that they are certainly useful for pass- and return-by-value
// as done with the ```TextQuery::query``` function, etc. 
//
// All the resources are handled by smart pointers without custom allocation,
// so copying and assigning is no problem.
//
// I commented the delete stuff out below.

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
        // TextQuery(const TextQuery &tq) = delete;
        // TextQuery& operator=(const TextQuery &tq) = delete;
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
        // QueryResult(const QueryResult &qr) = delete;
        // QueryResult& operator=(const QueryResult &qr) = delete;
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
