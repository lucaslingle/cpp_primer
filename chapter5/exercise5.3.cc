/*
Use the comma operator to rewrite the while loop from Sec 1.4.1 (p. 11)
so that it no longer requires a block. Explain whether this rewrite
improves or diminishes the readability of the code.
*/

#include <iostream>

void before() {
    int sum = 0, val = 1;
    while (val <= 10) {
        sum += val;
        ++val;
    }
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
}

void after() {
    int sum = 0;
    for (int val = 1; val <= 10; sum += val, ++val)
        ;
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
}

// for me, it helped the readability
