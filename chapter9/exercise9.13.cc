/*
How would you initialize a vector<double> from a list<int>?
From a vector<int>? Write code to check your answers.
*/

#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
using std::vector;
using std::list;
using std::cout;
using std::endl;

// i will just use iterators for the init, since they dont care about container type
// and allow implicit conversions of element types.
int main() {
    list<int> ls = {1, 2, 3};
    vector<double> v1(ls.cbegin(), ls.cend());
    cout << std::fixed << std::setprecision(1);
    for (auto const &elem : v1)
        cout << elem << " ";
    cout << endl;

    vector<int> vi = {1, 2, 3};
    vector<double> v2(vi.cbegin(), vi.cend());
    cout << std::fixed << std::setprecision(1);
    for (auto const &elem : v2)
        cout << elem << " ";
    cout << endl;

    return 0;
}
