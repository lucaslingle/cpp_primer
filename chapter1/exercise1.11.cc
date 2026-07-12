/*
Write a program that prompts the user for two integers.
Print each number in the range specified by those two integers.
*/

#include <iostream>

int main() {
    int v1 = 0, v2 = 0;
    std::cout << "Enter two numbers in ascending order:" << std::endl;
    std::cin >> v1 >> v2;
    while (v1 <= v2) {
        std::cout << v1 << std::endl;
        ++v1;
    }
    return 0;
}
