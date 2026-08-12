/*
Redefine bookstore without using decltype.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <set>

class Sales_data;
std::istream &read(std::istream &ist, Sales_data &data);

class Sales_data {
    friend std::istream &read(std::istream &ist, Sales_data &data);
    friend std::ostream &print(std::ostream &ost, const Sales_data &data);
    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
        double avg_price() const;
    public:
        Sales_data(const std::string &s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p*n) { }
        Sales_data(): Sales_data("", 0, 0.0) { }
        explicit Sales_data(const std::string &s): Sales_data(s, 0, 0.0) { }
        explicit Sales_data(std::istream &ist) { read(ist, *this); }
        Sales_data &combine(const Sales_data &elem) {
            units_sold += elem.units_sold;
            revenue += elem.revenue;
            return *this;
        }
        std::string isbn() const {
            return bookNo;
        }
};

inline double Sales_data::avg_price() const {
    return revenue / units_sold;
}

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

bool compare_isbn(const Sales_data &d1, const Sales_data &d2) {
    return d1.isbn() < d2.isbn();
}

int main() {
    std::multiset<Sales_data, bool(*)(const Sales_data&, const Sales_data&)> bookstore(compare_isbn);
    return 0;
}
