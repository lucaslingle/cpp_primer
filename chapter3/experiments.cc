#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec(10);
    for (auto i : vec)
        std::cout << i << std::endl;

    std::cout << "____" << std::endl;

    int arr[10];
    for (auto i : arr)
        std::cout << i << std::endl;
    return 0;
}
