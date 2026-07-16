/*
Compile and execute the bookstore program.
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
    Sales_data total;
    if (std::cin >> total.bookNo) {
        std::cin >> total.units_sold;
        std::cin >> price;
        total.revenue = total.units_sold * price;

        Sales_data trans;
        while (std::cin >> trans.bookNo) {
            std::cin >> trans.units_sold;
            std::cin >> price;
            trans.revenue = trans.units_sold * price;

            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                std::cout << total.bookNo << " " 
                          << total.units_sold << " "
                          << total.revenue << " "
                          << std::endl;
                total = trans;
            }
        }
        std::cout << total.bookNo << " " 
                  << total.units_sold << " "
                  << total.revenue << " "
                  << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
