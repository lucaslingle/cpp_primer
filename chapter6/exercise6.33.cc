/*
Write a recursive function to print the contents of a vector.
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void vecprint(vector<int> v) {
    static decltype(v)::size_type index = 0;
    if (index == v.size()) {
        cout << endl;
        index = 0;
        return;
    }
    cout << v[index++] << " ";
    vecprint(v);
}

void vecprint2(vector<int>::iterator beg, vector<int>::iterator end) {
    if (beg != end) {
        cout << *beg++ << " ";
        vecprint2(beg, end);
        return;
    }
    cout << endl;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    vecprint(vec);
    vecprint2(vec.begin(), vec.end());
    return 0;
}
