/*
Write a class that tests whether two values are equal. Use that object
and the library algorithms to write a program to replace all instances
of a given value in a sequence.
*/

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;
using std::vector;
using std::bind;
using namespace std::placeholders;
using std::replace_if;

class Equalizer {
public:
    bool operator()(const string &lhs, const string &rhs) {
        return lhs == rhs;
    }
};

int main() {
    Equalizer eq;
    vector<string> vec = {"Hello", "World", "Greetings", "World"};
    auto func = bind(eq, _1, "World");
    replace_if(vec.begin(), vec.end(), func, string("Earth"));
    
    for (const auto &s : vec)
        cout << s << " ";
    cout << endl;
    return 0;
}