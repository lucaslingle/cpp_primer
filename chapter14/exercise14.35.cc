/*
Write a class like PrintString that reads a line of input from an istream
and returns a string representing what was read. If the read fails, 
return the empty string. 
*/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

class LineReader {
    public:
        string operator()(istream& ist) const {
            string line;
            return (getline(ist, line)) ? line : "";
        }
};

int main() {
    LineReader reader;
    cout << reader(cin) << endl;
    return 0;
}
