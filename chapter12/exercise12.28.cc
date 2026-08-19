/*
Write a program to implement text queries without defining classes to 
manage the data. Your program should take a file and interact with the 
user to query for words in the file. Use vector, map, and set containers
to hold the data and to generate the results for the queries.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <cstddef>
// #include <memory>
#include <vector>
#include <stdexcept>
// using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::ifstream;
using std::istringstream;
using std::getline;
// using std::shared_ptr;
// using std::make_shared;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::runtime_error;
using std::out_of_range;

using VectorType = vector<string>;
using SetType = set<size_t>;
using MapType = map<string, SetType>;

int main(int argc, char *argv[]) {
    if (argc != 2)
        throw runtime_error("bad format. expected: prog.o fname");

    ifstream inp(argv[1]);
    VectorType lines;
    MapType word2idxs;

    size_t lineno = 0;
    string line;
    while (getline(inp, line)) {
        lines.push_back(line);
        istringstream linestream(line);
        string word;
        while (linestream >> word)
            word2idxs[word].insert(lineno);
        ++lineno;
    }
    
    while (true) {
        cout << "enter word to look for or q to quit: " << endl;
        string s;
        if (!(cin >> s) || s == "q")
            break;

        try {
            SetType linenos = word2idxs.at(s);
            for (size_t lineno : linenos)
                cout << lineno << ": " << lines.at(lineno) << endl;  
        } catch (const out_of_range& e) {
            cout << "Query string had no matches." << endl;
        }
    }

    return 0;
}
