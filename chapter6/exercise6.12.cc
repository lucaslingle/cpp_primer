/*
Rewrite the program from exercise 6.10 to use references instead of pointers
to swap the two ints. What version do you think would be easier to use and why?
*/

// this version slightly easier to use, dont have to take the address of i,j in main.
// also no need for dereferencing pointers in myswap function body.

#include <iostream>

void myswap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int i = 0;
    int j = 1;
    std::cout << "(i, j) == (" << i << ", " << j << ")" << std::endl;
    myswap(i, j);
    std::cout << "(i, j) == (" << i << ", " << j << ")" << std::endl;

    return 0;
}
