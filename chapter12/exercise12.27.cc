/*
The TextQuery and QueryResult classes use only capabilities that
we have already covered. Without looking ahead, write your own
version of these classes.
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
                    if (word2idxs->find(word) != word2idxs->end())
                        word2idxs->at(word)->insert(lineno);
                    else {
                        shared_ptr<SetType> nos = make_shared<SetType>();
                        nos->insert(lineno);
                        (*word2idxs)[word] = nos;
                    }
                }
                ++lineno;
            }
        }
        shared_ptr<QueryResult> query(const string &word);
    private:
        shared_ptr<VectorType> lines = make_shared<VectorType>();
        shared_ptr<MapType> word2idxs = make_shared<MapType>();
};

class QueryResult {
    friend void print(ostream&, shared_ptr<QueryResult>);
    public:
        QueryResult(shared_ptr<VectorType> v, 
                    shared_ptr<MapType> m, 
                    const string &s): lines(v), word2idxs(m), query(s) { }
    private:
        shared_ptr<VectorType> lines;
        shared_ptr<MapType> word2idxs;
        const string query;
};

shared_ptr<QueryResult> TextQuery::query(const string &word) {
    return make_shared<QueryResult>(this->lines, this->word2idxs, word);
}

void print(ostream& ost, shared_ptr<QueryResult> queryresult) {
    auto qr = *queryresult.get();
    try {
        shared_ptr<SetType> linenos = qr.word2idxs->at(qr.query);
        for (size_t lineno : *linenos)
            ost << lineno << ": " << qr.lines->at(lineno) << endl;  
    } catch (const out_of_range& e) {
        cout << "Query string had no matches." << endl;
        return;
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
