/*
Write a program that reads several transactions for the same ISBN.
Write the sum of all transactions that were read.
*/

#include <iostream>
#include <string>
#include "Sales_data.h"

int main() {
    double price;
    Sales_data sum, item;

    while (std::cin >> item.bookNo) {
        std::cin >> item.units_sold;
        std::cin >> price;
        item.revenue = item.units_sold * price;

        if (sum.bookNo == "")
            sum.bookNo = item.bookNo;
        if (sum.bookNo != item.bookNo)
            std::cout << "ISBNs don't match" << std::endl;

        sum.units_sold += item.units_sold;
        sum.revenue += item.revenue;
    }

    std::cout << sum.bookNo << " " 
              << sum.units_sold << " "
              << sum.revenue << " "
              << std::endl;
}
