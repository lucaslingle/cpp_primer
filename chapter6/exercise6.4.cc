/*
Write a function that interacts with the user, asking for a number
and generating the factorial of that number. Call this function from main.
*/

#include <iostream>

int fact(int n) {
    int result = 1;
    while (n >= 1)
        result *= n--;
    return result;
}

int main() {
    int n;
    std::cout << "Give me an integer n." << std::endl;
    std::cin >> n;
    std::cout << "The factorial of n is " << fact(n) << std::endl;
    return 0;
}
