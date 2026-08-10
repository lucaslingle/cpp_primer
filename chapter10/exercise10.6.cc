/*
Using fill_n, write a program to set a sequence of int values to 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4};
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    fill_n(vec.begin(), vec.size(), 0);
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}