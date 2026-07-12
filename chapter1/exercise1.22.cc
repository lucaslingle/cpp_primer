/*
Write a program that reads several transactions for the same ISBN.
Write the sum of all transactions that were read.
*/

#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item isum, ival;
    if (std::cin >> isum) {
        while (std::cin >> ival) {
            if (ival.isbn() != isum.isbn()) {
                std::cout << "Error: ISBNs do not match." << std::endl;
                return -1;
            }
            isum += ival;
        }
        std::cout << isum << std::endl;
    }
    return 0;
}
