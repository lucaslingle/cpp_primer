/*
Write the condition for a while loop that would read ints from standard input
and stop when the value read is equal to 42.
*/

#include <iostream>

int main() {
    int val;
    while (std::cin >> val && val != 42)
        std::cout << val << " ";
    std::cout << std::endl;
    return 0;
}
