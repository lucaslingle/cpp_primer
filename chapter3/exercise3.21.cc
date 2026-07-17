/*
Redo exercise 3.16 using iterators.
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
    for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
        cout << *it << ", ";
    cout << "}";
    cout << endl;
}

void print_svec(vector<string> svec) {
    cout << "{";
    for (auto it = svec.cbegin(); it != svec.cend(); ++it)
        cout << *it << ", ";
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
    
    return 0;
}
