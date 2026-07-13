/*
Using generalized escape sequences, write a program to print 2M followed by a newline.
Modify the program to print 2, then a tab, then an M, followed by a newline.
*/

#include <iostream>

int main() {
    std::cout << '\x32' << '\x09' << '\x4d' << '\x0d' << std::endl;
    return 0;
}
