/*
void fcn(const int i); // "fcn can read but not write to i." 
void fcn(int i);       // "error: redefines fcn(int)"
*/

#include <iostream>

void fcn(const int i) {
    std::cout << i << std::endl;
    i = 42;
    std::cout << i << std::endl;
}

void fcn(int i) {
    std::cout << i << std::endl;
    i = -1;
    std::cout << i << std::endl;
}

int main() {
    int i = 0;
    fcn(i);
    return 0;
}
