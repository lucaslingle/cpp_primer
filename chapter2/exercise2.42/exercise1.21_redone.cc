/*
Write a program that reads two Sales_item objects that have the same ISBN
and produces their sum.
*/

#include <iostream>
#include <string>
#include "Sales_data.h"

int main() {
    double price;
    Sales_data item, item2, item3;

    std::cin >> item.bookNo;
    std::cin >> item.units_sold;
    std::cin >> price;
    item.revenue = item.units_sold * price;

    std::cin >> item2.bookNo;
    std::cin >> item2.units_sold;
    std::cin >> price;
    item2.revenue = item2.units_sold * price;

    item3.bookNo = item.bookNo;
    item3.units_sold = item.units_sold + item2.units_sold;
    item3.revenue = item.revenue + item2.revenue;

    std::cout << item3.bookNo << " " 
              << item3.units_sold << " "
              << item3.revenue << " "
              << std::endl;

    return 0;
}
