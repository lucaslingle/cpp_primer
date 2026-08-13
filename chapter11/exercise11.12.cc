/*
Write a program to read a sequence of strings and ints,
storing each into a pair. Store the pairs in a vector.
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>
using Pair = std::pair<std::string, int>;

int main() {
    Pair kv;
    std::vector<Pair> vec;
    while (std::cin >> kv.first >> kv.second)
        vec.push_back(kv);
    for (const auto &pr : vec)
        std::cout << "(" << pr.first << ", " << pr.second << ")" << std::endl;
    return 0;
}
