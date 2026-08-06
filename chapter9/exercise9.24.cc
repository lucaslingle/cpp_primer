/*
Write a program that fetches the first element in a vector 
using at, subscript, front, and begin. Test your program on an empty vector.
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    // comment all but one out to see what happens
    // i got out_of_bounds error for vec.at(0) and segfault for the rest.
    std::cout << vec.at(0) << std::endl;
    std::cout << vec[0] << std::endl;
    std::cout << vec.front() << std::endl;
    std::cout << *vec.begin() << std::endl;
    return 0;
}
