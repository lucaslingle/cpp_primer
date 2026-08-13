/*
There are at least three ways to create the pairs in the program for the 
previous exercise. Write three versions of that program, creating the pairs
in each way. Explain which form you think is easiest to write and understand 
and why.
*/

// the first or second way is easiest to write and understand.
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using Pair = std::pair<std::string, int>;

void print_vec_of_pairs(const std:vector<Pair> &vec) {
    for (const auto &pr : vec)
        std::cout << "(" << pr.first << ", " << pr.second << ")" << std::endl;
}

void first_way() {
    Pair kv;
    std::vector<Pair> vec;
    while (std::cin >> kv.first >> kv.second)
        vec.push_back(kv);
    print_vec_of_pairs(vec);
}

void second_way() {
    std::string first, int second;
    std::vector<Pair> vec;
    while (std::cin >> first >> second)
        vec.emplace_back(first, second);
    print_vec_of_pairs(vec);
}

void third_way() {
    std::string first, int second;
    std::vector<Pair> vec;
    while (std::cin >> first >> second)
        vec.push_back(std::make_pair(first, second));
    print_vec_of_pairs(vec);
}

void fourth_way() {
    std::string first, int second;
    std::vector<Pair> vec;
    while (std::cin >> first >> second) {
        Pair kv(first, second);
        vec.push_back(kv);
    }
    print_vec_of_pairs(vec);
}
