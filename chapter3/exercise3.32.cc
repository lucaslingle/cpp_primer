/*
Copy the array you defined in the previous exercise into another array.
Rewrite your program to use vectors.
*/

#include <iostream>
#include <vector>
#include <cstddef>

int main() {
    int a1[10];
    for (std::size_t i = 0; i != 10; ++i)
        a1[i] = i;
    int a2[10];
    for (std::size_t i = 0; i != 10; ++i)
        a2[i] = a1[i];

    std::cout << "a2: ";
    for (auto i : a2)
        std::cout << i << " ";
    std::cout << std::endl;

    std::vector<int> v1;
    for (decltype(v1)::size_type i = 0; i != 10; ++i)
        v1.push_back(i);
    std::vector<int> v2(v1);

    std::cout << "v2: ";
    for (auto i : v2)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
