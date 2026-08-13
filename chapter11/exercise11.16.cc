/*
Using a map iterator, write an expression that assigns a value to an element.
*/

#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> word_count = {{"Hello", 1}};
    auto it = word_count.begin();
    it->second = 2;
    for (const auto &elem : word_count)
        std::cout << elem.first << ", " << elem.second << std::endl;
    return 0;
}
