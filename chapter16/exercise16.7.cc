/*
Write a constexpr template that returns the size of a given array.
*/

#include <iostream>
#include <cstddef>

template <typename T, std::size_t N>
constexpr std::size_t my_arraysize(T (&ta)[N]) {
    return N;
}

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char arr2[5] = {'h', 'e', 'l', 'l', 'o'};

    std::cout << my_arraysize(arr) << std::endl;
    std::cout << my_arraysize(arr2) << std::endl;

    return 0;
}