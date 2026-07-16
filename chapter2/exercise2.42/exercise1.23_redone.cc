/*
Write a program that reads several transactions and counts 
how many transactions occur for each ISBN. 
*/

#include <iostream>
#include "Sales_data.h"

// assumption: the inputs are sorted by isbn already, as with exercises 1.17-1.18.
// assumption: want number of txs not number of copies, as units_sold is private var.
int main() {
    double price;
    Sales_data isum, ival;
    if (std::cin >> isum.bookNo) {
        std::cin >> isum.units_sold;
        std::cin >> price;
        isum.revenue = isum.units_sold * price;

        int cnt = 1;
        while (std::cin >> ival.bookNo) {
            std::cin >> ival.units_sold;
            std::cin >> price;
            ival.revenue = ival.units_sold * price;

            if (isum.bookNo == ival.bookNo) {
                ++cnt;
            } else {
                std::cout << isum.bookNo << " has "
                          << cnt << " transactions." << std::endl;
                isum = ival;
                cnt = 1;
            }
        }
        std::cout << isum.bookNo << " has "
                  << cnt << " transactions." << std::endl;
    }
    return 0;
}
