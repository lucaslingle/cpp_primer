/*
Redo exercise 3.20 using iterators.
*/

#include <iostream>
#include <vector>

int main() {
    int i;
    std::vector<int> vec;
    while (std::cin >> i)
        vec.push_back(i);
    
    std::cout << "Adjacent element sums:" << std::endl;
    for (auto it = vec.cbegin(); it != vec.cend() - 1; ++it)
        std::cout << (*it + *(it + 1)) << std::endl;

    std::cout << "Opposite side elements:" << std::endl;
    for (auto beg = vec.cbegin(), end = vec.cend() - 1; beg <= end; ++beg, --end) {
        std::cout << *beg << std::endl;
        if (beg < end)
            std::cout << *end << std::endl;
    }
    return 0;
}
