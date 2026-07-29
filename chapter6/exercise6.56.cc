/*
Call each element in the vector and print the result.
*/

#include <iostream>
#include <vector>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main() {
    std::vector<int(*)(int, int)> vec = {add, subtract, multiply, divide};
    for (auto f : vec)
        std::cout << f(10, 2) << std::endl;
    return 0;
}
