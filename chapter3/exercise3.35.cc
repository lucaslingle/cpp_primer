/*
Using pointers, write a program to set the elements in an array to zero.
*/

#include <iostream>
#include <iterator>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "initial:" << std::endl;
    for (int *b = std::begin(arr); b != std::end(arr); ++b)
        std::cout << *b << " ";
    std::cout << std::endl;

    for (int *b = std::begin(arr); b != std::end(arr); ++b)
        *b = 0;

    std::cout << "final:" << std::endl;
    for (int *b = std::begin(arr); b != std::end(arr); ++b)
        std::cout << *b << " ";
    std::cout << std::endl;

    return 0;
}
