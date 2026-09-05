/*
Write conversion operators to convert a `Sales_data` to `string` and `double`.
What values do you think these operators should return?
*/

// probably the ISBN and revenue, respectively.

#include <iostream>
#include <string>
#include <stdexcept>

class Sales_data;

std::istream& operator>>(std::istream &ist, Sales_data &data);
std::ostream& operator<<(std::ostream &ost, const Sales_data &data);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&); 
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
        Sales_data& operator=(const std::string &isbn);
        std::string isbn() const {
            return bookNo;
        }
        explicit operator std::string() const { return bookNo; }
        explicit operator double() const { return revenue; }
};

inline double Sales_data::avg_price() const {
    return (units_sold) ? (revenue / units_sold) : 0.0;
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

Sales_data& Sales_data::operator=(const std::string &isbn) {
    bookNo = isbn;
    units_sold = 0;
    revenue = 0.0;
    return *this;
}
