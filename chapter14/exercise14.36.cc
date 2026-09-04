/*
Use the class from the previous exercise to read the standard input,
storing each line as an element in a vector.
*/

#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;
using std::vector;

class LineReader {
    public:
        string operator()(istream& ist) const {
            string line;
            return (getline(ist, line)) ? line : "";
        }
};

int main() {
    vector<string> vec;
    LineReader reader;
    string line;
    while ((line = reader(cin)) != "")
        vec.push_back(line);
    for (const auto &s : vec)
        cout << s << " ";
    cout << endl;
    
    return 0;
}
