/*
Write a version of the transaction processing program from exercise 1.25
using the Sales_data class you defined in exercise 2.40.
*/

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo = "";
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline std::istream &read(std::istream &ist, struct Sales_data &data) {
    ist >> data.bookNo >> data.units_sold >> data.revenue;
    return ist;
}

inline bool isbn_equal(const struct Sales_data &d1, const struct Sales_data &d2) {
    return (d1.bookNo == d2.bookNo);
}

inline void combine(struct Sales_data &acc, const struct Sales_data &elem) {
    acc.units_sold += elem.units_sold;
    acc.revenue += elem.revenue;
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
            if (isbn_equal(total, trans))
                combine(total, trans);
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
