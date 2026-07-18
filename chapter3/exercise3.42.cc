/*
Write a program to copy a vector of ints into an array of ints.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <cstddef>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr[10] = {};
    for (std::size_t i = 0; i != 10; ++i)
        arr[i] = vec[i];

    for (int *b = std::begin(arr); b != std::end(arr); ++b)
        std::cout << *b << " ";
    std::cout << std::endl;
    return 0;
}
