/*
Add constructors to your Sales_data class 
and write a program to use each of the constructors. 
*/

#include <iostream>
#include <string>
#include <vector>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &ist);

    Sales_data &combine(const Sales_data &elem) {
        units_sold += elem.units_sold;
        revenue += elem.revenue;
        return *this;
    }

    std::string isbn() const {
        return bookNo;
    }

    double avg_price() const {
        return revenue / units_sold;
    }
};

std::istream &read(std::istream &ist, Sales_data &data) {
    double price;
    ist >> data.bookNo >> data.units_sold >> price;
    data.revenue = price * data.units_sold;
    return ist;
}

std::ostream &print(std::ostream &ost, const Sales_data &data) {
    ost << data.bookNo << " " 
        << data.units_sold << " " 
        << data.revenue << " "
        << data.avg_price();
    return ost;
}

Sales_data::Sales_data(std::istream &ist) {
    read(ist, *this);
}

int main() {
    Sales_data a = Sales_data();
    Sales_data b = Sales_data("bbb");
    Sales_data c = Sales_data("ccc", 10, 42.00);
    Sales_data d = Sales_data(std::cin);
    std::vector<Sales_data> vec = {a, b, c, d};
    for (auto sd : vec)
        print(std::cout, sd) << std::endl;
    return 0;
}
