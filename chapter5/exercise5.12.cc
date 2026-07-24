/*
Modify our vowel counting program so that it counts the number of 
occurrences of the following two-letter sequences: ff, fl, fi.
*/

#include <iostream>

int main() {
    int acount = 0, ecount = 0, icount = 0, ocount = 0, ucount = 0;
    int ffcount = 0, flcount = 0, ficount = 0;
    char letter;
    bool prevf = false;

    std::cout << "enter text:" << std::endl;
    while (std::cin.get(letter)) {
        switch (letter) {
            case 'a':
                ++acount;
                prevf = false;
                break;
            case 'e':
                ++ecount;
                prevf = false;
                break;
            case 'i':
                ++icount;
                if (prevf)
                    ++ficount;
                prevf = false;
                break;
            case 'o':
                ++ocount;
                prevf = false;
                break;
            case 'u':
                ++ucount;
                prevf = false;
                break;
            case 'f':
                if (prevf)
                    ++ffcount;
                prevf = true;
                break;
            case 'l':
                if (prevf)
                    ++flcount;
                prevf = false;
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

    std::cout << "num ff: \t" << ffcount << std::endl;
    std::cout << "num fl: \t" << flcount << std::endl;
    std::cout << "num fi: \t" << ficount << std::endl;

    return 0;
}
