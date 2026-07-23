/*
Assuming i is an int and d is a double, write the expression ```i *= d```
so that it does integral, rather than floating-point, multiplication.
*/

// i *= static_cast<int>(d)

#include <iostream>

int main() {
    int i = 2;
    double d = 0.5;
    i *= d;
    std::cout << i << std::endl;

    int i2 = 2;
    double d2 = 0.5;
    i2 *= static_cast<int>(d2);
    std::cout << i2 << std::endl;
}
