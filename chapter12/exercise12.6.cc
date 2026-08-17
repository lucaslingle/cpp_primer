/*
Write a function that returns a dynamically allocated vector of ints.

Pass that vector to another function that reads the standard input 
to give values to the elements. 

Pass the vector to another function to print the values that were read.

Remember to delete the vector at the appropriate time.
*/

#include <iostream>
#include <vector>
#include <new>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int>* factory() {
    vector<int> *vec = new vector<int>();
    return vec;
}

void read_cin(vector<int> *vec) {
    int elem;
    while (cin >> elem)
        vec->push_back(elem);
}

void print_vec(vector<int> *vec) {
    for (int elem : *vec)
        cout << elem << " ";
    cout << endl;
}

int main() {
    vector<int> *vec = factory();
    read_cin(vec);
    print_vec(vec);
    delete vec;
}
