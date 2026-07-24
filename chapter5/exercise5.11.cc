/*
Modify our vowel counting program, so that it also counts the 
number of blank spaces, tabs, and newlines read.
*/

#include <iostream>

int main() {
    int acount = 0, ecount = 0, icount = 0, ocount = 0, ucount = 0;
    int spacecount = 0, tabcount = 0, newlinecount = 0;
    char letter;

    std::cout << "enter text:" << std::endl;
    while (std::cin.get(letter)) {
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
            case ' ':
                ++spacecount;
                break;
            case '\t':
                ++tabcount;
                break;
            case '\n':
                ++newlinecount;
                break;
            default:
                ; // null statement
        }
    }
    std::cout << "num a: \t" << acount << std::endl;
    std::cout << "num e: \t" << ecount << std::endl;
    std::cout << "num i: \t" << icount << std::endl;
    std::cout << "num o: \t" << ocount << std::endl;
    std::cout << "num u: \t" << ucount << std::endl;

    std::cout << "num space: \t" << spacecount << std::endl;
    std::cout << "num tab: \t" << tabcount << std::endl;
    std::cout << "num newline: \t" << newlinecount << std::endl;
    return 0;
}
