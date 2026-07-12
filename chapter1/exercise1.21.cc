/*
Write a program that reads two Sales_item objects that have the same ISBN
and produces their sum.
*/

#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item i1, i2;
    std::cin >> i1 >> i2;
    if (i1.isbn() != i2.isbn()) {
        std::cout << "Error: ISBNs do not match." << std::endl;
        return -1;
    }
    std::cout << i1 + i2 << std::endl;
    return 0;
}
