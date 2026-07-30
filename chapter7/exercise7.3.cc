/*
Revise your transaction processing program from exercise 7.1
to use these members.
*/

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data &combine(const struct Sales_data &elem) {
        units_sold += elem.units_sold;
        revenue += elem.revenue;
        return *this;
    }

    std::string isbn() const {
        return bookNo;
    }
};

inline std::istream &read(std::istream &ist, struct Sales_data &data) {
    ist >> data.bookNo >> data.units_sold >> data.revenue;
    return ist;
}

inline std::ostream &print(std::ostream &ost, struct Sales_data &data) {
    ost << data.bookNo << " " << data.units_sold << " " << data.revenue;
    return ost;
}

int main() {
    Sales_data total;
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
