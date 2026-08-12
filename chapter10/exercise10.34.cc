/*
Use reverse_iterators to print a vector in reverse order.
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = vec.crbegin(); it != vec.crend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    return 0;
}
