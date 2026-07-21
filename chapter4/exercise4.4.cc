/*
Parenthesize the following expression to show how it is evaluated.
Test your answer by compiling the expression without parentheses 
and printing the result. 

12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
*/

// my answer:
// (((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2)

#include <iostream>

int main() {
    int v_actual = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
    int v_expected = (((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2);
    std::cout << v_actual << std::endl;
    std::cout << v_expected << std::endl;
    return 0;
}
