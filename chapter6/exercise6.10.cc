/*
Using pointers, write a function to swap the values of two ints.
Test the function by calling it and printing the swapped values.
*/

#include <iostream>

void myswap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int i = 0;
    int j = 1;
    std::cout << "(i, j) == (" << i << ", " << j << ")" << std::endl;
    myswap(&i, &j);
    std::cout << "(i, j) == (" << i << ", " << j << ")" << std::endl;

    return 0;
}
