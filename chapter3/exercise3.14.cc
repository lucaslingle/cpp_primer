/*
Write a program to read a sequence of ints from cin 
and store those values in a vector. 
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int element;
    vector<int> vec;
    while (cin >> element)
        vec.push_back(element);
    cout << "{";
    for (auto i : vec)
        cout << i << ", ";
    cout << "}";
    cout << endl;
}
