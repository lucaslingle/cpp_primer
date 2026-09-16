/*
Write a template that acts like the library `find` algorithm.
The function will need two template type parameters, one to represent the 
function's iterator parameters and the other for the type of the value.
Use your function to find a given value in a `vector<int>` and a `list<string>`.
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>

template <typename IterType, typename ValueType>
IterType my_find(IterType begin, IterType end, ValueType val) {
    while (begin != end) {
        if (*begin == val)
            return begin;
        ++begin;
    }
    return end;
}

int main() {
    std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<std::string> slst = {"hello", "world", "greetings", "planet"};

    std::cout << 7 << " " << *my_find(ivec.begin(), ivec.end(), 7) << std::endl;
    std::cout << "greetings " << *my_find(slst.begin(), slst.end(), "greetings") << std::endl;

    return 0;
}