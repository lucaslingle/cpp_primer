/*
Write a program to use a conditional operator to find the elements in a 
vector<int> that have odd value and double the value of each such element. 
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : vec)
        i = i % 2 ? 2 * i : i;
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
