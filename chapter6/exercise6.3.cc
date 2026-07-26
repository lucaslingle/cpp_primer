/*
Write and test your own version of ```fact```.
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
    std::cin >> n;
    std::cout << fact(n) << std::endl;
    return 0;
}
