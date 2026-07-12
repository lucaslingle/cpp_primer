/*
Revise the program you wrote for the exercises in Section 1.4.1 that
printed a range of numbers so that it handles input in which the first number is
larger or smaller than the second.
*/

#include <iostream>

int main() {
    int v1 = 0, v2 = 0;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;
    if (v1 <= v2)
        while (v1 <= v2) {
            std::cout << v1 << std::endl;
            ++v1;
        }
    else
        while (v1 >= v2) {
            std::cout << v1 << std::endl;
            --v1;
        }
    return 0;
}
