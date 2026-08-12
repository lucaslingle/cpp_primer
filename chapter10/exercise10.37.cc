/*
Given a vector that has ten elements, 
copy the elements from position 3 thru 7 in reverse order to a list.
*/

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main() {
    std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto start = ivec.crbegin() + ((10 - 1) - 7); // inclusive of position 7
    auto end = ivec.crend() - (1 + (3 - 1));  // inclusive of position 3

    std::list<int> ls;
    std::copy(start, end, std::back_inserter(ls));  
    // it wouldve been easier to just use front_inserter instead of reverse iterators
    // but this is the reverse iterator section.

    for (auto i : ls)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
