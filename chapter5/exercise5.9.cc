/*
Write a program using a series of if statements to count
the number of vowels in text read from cin.
*/

#include <iostream>
#include <string>

int main() {
    int vowel_count = 0;
    std::string word;

    std::cout << "enter text:" << std::endl;
    while (std::cin >> word) {
        for (auto letter : word) {
            if (letter == 'a')
                ++vowel_count;
            if (letter == 'e')
                ++vowel_count;
            if (letter == 'i')
                ++vowel_count;
            if (letter == 'o')
                ++vowel_count;
            if (letter == 'u')
                ++vowel_count;
        }
    }
    std::cout << "num vowels:\n" << vowel_count << std::endl;
    return 0;
}
