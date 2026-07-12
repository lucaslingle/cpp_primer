/*
Write a program that reads several transactions and counts 
how many transactions occur for each ISBN. 
*/

#include <iostream>
#include "Sales_item.h"

// assumption: the inputs are sorted by isbn already, as with exercises 1.17-1.18.
// assumption: want number of txs not number of copies, as units_sold is private var.
int main() {
    Sales_item isum, ival;
    if (std::cin >> isum) {
        int cnt = 1;
        while (std::cin >> ival) {
            if (isum.isbn() == ival.isbn()) {
                ++cnt;
            } else {
                std::cout << isum.isbn() << " has "
                          << cnt << " transactions." << std::endl;
                isum = ival;
                cnt = 1;
            }
        }
        std::cout << isum.isbn() << " has "
                  << cnt << " transactions." << std::endl;
    }
    return 0;
}
