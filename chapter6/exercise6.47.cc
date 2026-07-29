/*
Revise the program you wrote in the exercises in Sec 6.3.2 (p. 228) that used
recursion to print the contents of a vector to conditionally print information
about its execution. For example, you might print the size of the vector 
on each call. Compile and run the program with debugging turned on 
and again with it turned off.
*/

// i.e., compile with one of:
// clang++ -std=c++11 -stdlib=libc++ exercise6.47.cc
// clang++ -std=c++11 -stdlib=libc++ -DNDEBUG exercise6.47.cc

#include <iostream>
#include <vector>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

void vecprint(vector<int> v) {
    static decltype(v)::size_type index = 0;

    #ifndef NDEBUG
    cerr << __func__ << ": vector tail len is " << v.size() - index << endl;
    #endif

    if (index == v.size()) {
        cout << endl;
        index = 0;
        return;
    }
    cout << v[index++] << " ";
    vecprint(v);
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    vecprint(vec);
    return 0;
}
