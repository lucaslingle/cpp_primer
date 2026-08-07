/*
Write a program to explore how vectors grow in the library you use.
*/

#include <iostream>
#include <vector>

void print_stats(const std::vector<int> &vec) {
    std::cout << "\tsize: " << vec.size() 
              << ", capacity: " << vec.capacity() 
              << std::endl;
}

void fill_to_capacity(std::vector<int> &vec) {
    auto capacity = vec.capacity();
    auto size = vec.size();
    for (int i = 0; i != capacity - size; ++i)
        vec.push_back(i);
}

int main() {
    std::vector<int> vec;
    print_stats(vec);

    for (int i = 0; i != 10; ++i) {
        std::cout << "at capacity" << std::endl;
        fill_to_capacity(vec);
        print_stats(vec);

        std::cout << "pushed past capacity" << std::endl;
        vec.push_back(-1);
        print_stats(vec);
    }

    return 0;
}