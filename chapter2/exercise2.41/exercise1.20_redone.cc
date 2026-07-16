/*
Write a program that reads a set of book sales transactions,
writing each transaction to standard output.
*/

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo = "";
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main() {
    double price;
    Sales_data item;
    while (std::cin >> item.bookNo) {
        std::cin >> item.units_sold;
        std::cin >> price;
        item.revenue = item.units_sold * price;
        std::cout << item.bookNo << " " 
                  << item.units_sold << " "
                  << item.revenue << " "
                  << std::endl;
    }
    return 0;
}
