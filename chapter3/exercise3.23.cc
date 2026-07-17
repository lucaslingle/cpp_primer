/*
Write a program to create a vector with ten int elements.
Using an iterator, assign each element a value twice its current value.
Test your program by printing the vector.
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = vec.begin(); it != vec.end(); ++it)
        *it = 2 * *it;
    std::cout << "{ ";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << *it;
        std::cout << ", ";
    }
    std::cout << "}";
    std::cout << std::endl;
    return 0;
}
