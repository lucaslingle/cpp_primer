/*
Redo the previous exercise, this time using shared_ptr.
*/

#include <iostream>
#include <vector>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

shared_ptr<vector<int>> factory() {
    shared_ptr<vector<int>> vec = make_shared<vector<int>>();
    return vec;
}

void read_cin(shared_ptr<vector<int>> vec) {
    int elem;
    while (cin >> elem)
        vec->push_back(elem);
}

void print_vec(shared_ptr<vector<int>> vec) {
    for (int elem : *vec)
        cout << elem << " ";
    cout << endl;
}

int main() {
    shared_ptr<vector<int>> vec = factory();
    read_cin(vec);
    print_vec(vec);
}
