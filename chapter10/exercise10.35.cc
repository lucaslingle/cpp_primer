/*
Now print the elements in reverse order using ordinary iterators.
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = vec.end(); it != vec.begin(); --it)
        std::cout << *(it-1) << " ";
    std::cout << std::endl;
    return 0;
}
