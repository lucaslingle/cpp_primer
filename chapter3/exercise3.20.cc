/*
Read a set of integers into a vector. Print the sum of each pair
of adjacent elements. Change your program so that it prints the sum of the
first and last elements, followed by the sum of the second and second-to-last, 
and so on.
*/

#include <iostream>
#include <vector>

int main() {
    int i;
    std::vector<int> vec;
    while (std::cin >> i)
        vec.push_back(i);
    
    std::cout << "Adjacent element sums:" << std::endl;
    for (decltype(vec)::size_type j = 0; j < vec.size() - 1; ++j)
        std::cout << vec[j] + vec[j+1] << std::endl;

    std::cout << "Opposite side elements:" << std::endl;
    for (decltype(vec)::size_type j = 0; j < (vec.size() + 1) / 2; ++j) {
        std::cout << vec[j] << std::endl;
        if (vec.size() - j - 1 != j)
            std::cout << vec[vec.size() - j - 1] << std::endl;
    }
    return 0;
}
