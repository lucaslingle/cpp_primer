/*
Write a program to print the size and contents of vectors from exercise 3.13.
Check whether your answers to that exercise were correct. If not restudy Sec 3.3.1
until you understand why you were wrong.
*/

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void print_ivec(vector<int> ivec) {
    cout << "{";
    for (auto i : ivec)
        cout << i << ", ";
    cout << "}";
    cout << endl;
}

void print_svec(vector<string> svec) {
    cout << "{";
    for (auto s : svec)
        cout << s << ", ";
    cout << "}";
    cout << endl;
}

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    
    print_ivec(v1);
    print_ivec(v2);
    print_ivec(v3);
    print_ivec(v4);
    print_ivec(v5);

    print_svec(v6);
    print_svec(v7);
}

/*
output:
{}
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }
{42, 42, 42, 42, 42, 42, 42, 42, 42, 42, }
{10, }
{10, 42, }
{, , , , , , , , , , }
{hi, hi, hi, hi, hi, hi, hi, hi, hi, hi, }

matches 3.13 answers:
// (a) empty vector with no elements.
// (b) vector of length 10 with default initialization (element value 0).
// (c) vector of length 10 with 42 as each element's value.
// (d) vector of length 1 with 10 as the element value.
// (e) vector of length 2 with {10, 42} as the element values.
// (f) vector of length 10 with "" as each element's value.
// (g) vector of length 10 with "hi" as each element's value.
*/