/*
Write a program that reads a string of characters including punctuation
and writes what was read but with punctuation removed.
*/

#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        for (auto c : line)
            if (!std::ispunct(c))
                std::cout << c;
        std::cout << std::endl;
    }
    return 0;
}
