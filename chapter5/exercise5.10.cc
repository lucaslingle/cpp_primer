/*
There is one problem with our vowel counting program as we've implemented it:
It doesn't count capital letters as vowels. Write a program that counts both
uppercase and lowercase letters as the appropriate vowel--that is, your program
should count both 'a' and 'A' as part of aCnt and so on.
*/

#include <iostream>
#include <string>
#include <cctype>

int main() {
    int acount = 0, ecount = 0, icount = 0, ocount = 0, ucount = 0;
    std::string word;

    std::cout << "enter text:" << std::endl;
    while (std::cin >> word) {
        for (auto letter : word) {
            letter = std::tolower(letter);
            switch (letter) {
                case 'a':
                    ++acount;
                    break;
                case 'e':
                    ++ecount;
                    break;
                case 'i':
                    ++icount;
                    break;
                case 'o':
                    ++ocount;
                    break;
                case 'u':
                    ++ucount;
                    break;
                default:
                    ; // null statement
            }
        }
    }
    std::cout << "num a: \t" << acount << std::endl;
    std::cout << "num e: \t" << ecount << std::endl;
    std::cout << "num i: \t" << icount << std::endl;
    std::cout << "num o: \t" << ocount << std::endl;
    std::cout << "num u: \t" << ucount << std::endl;
    return 0;
}
