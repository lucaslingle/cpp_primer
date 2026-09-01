/*
What other arithmetic operators if any do you think Sales_data
ought to support? Define any you think the class should include.
*/

// could do multiplication, so if there are multiple orders of the same size
// the total works:

#include <iostream>
#include <string>
#include <stdexcept>

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
        double avg_price() const;
    public:
        Sales_data(const std::string &s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p*n) { }
        Sales_data(): Sales_data("", 0, 0.0) { }
        Sales_data& operator+=(const Sales_data&);
        Sales_data& operator*=(unsigned);
        std::string isbn() const {
            return bookNo;
        }
};

inline double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0.0;
}

std::istream& operator>>(std::istream &ist, Sales_data &data) {
    double price;
    ist >> data.bookNo >> data.units_sold >> price;
    if (ist)
        data.revenue = price * data.units_sold;
    else
        data = Sales_data();
    return ist;
}

std::ostream& operator<<(std::ostream &ost, const Sales_data &data) {
    ost << data.bookNo << " " 
        << data.units_sold << " " 
        << data.revenue << " "
        << data.avg_price();
    return ost;
}

Sales_data& Sales_data::operator+=(const Sales_data &data) {
    if (this->isbn() != data.isbn())
        throw std::runtime_error("require same isbn for Sales_data compound addition.");
    units_sold += data.units_sold;
    revenue += data.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data& Sales_data::operator*=(unsigned multiplier) {
    units_sold *= multiplier;
    revenue *= multiplier;
    return *this;
}

Sales_data operator*(const Sales_data &lhs, unsigned rhs) {
    Sales_data product(lhs);
    product *= rhs;
    return product;
}

Sales_data operator*(unsigned lhs, const Sales_data &rhs) {
    Sales_data product(rhs);
    product *= lhs;
    return product;
}
