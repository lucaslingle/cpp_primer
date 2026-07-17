/*
Write a program to read a sequence of ints from cin 
and store those values in a vector. 
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    string element;
    vector<string> vec;
    while (cin >> element)
        vec.push_back(element);
    cout << "{";
    for (auto s : vec)
        cout << s << ", ";
    cout << "}";
    cout << endl;

    return 0;
}
