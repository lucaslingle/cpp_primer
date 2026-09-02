/*
Write the Sales_data operators so that + does the actual addition
and += calls +. Discuss the disadvantages of this approach compared
to the way these operators weredefined in p. 560 and p. 564.
*/

// as discussed in exercise 14.14:
//
// if operator+= called operator+
// then the operator+ would return the result by value, which would then 
// have to be copied/moved into the data members of *this. 
//
// so a temporary object is created and superfluous copies occur this other way. 

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
        std::string isbn() const {
            return bookNo;
        }
};

inline double Sales_data::avg_price() const {
    return revenue / units_sold;
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

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    if (lhs.isbn() != rhs.isbn())
        throw std::runtime_error("require same isbn for Sales_data compound addition.");
    units_sold = lhs.units_sold + rhs.units_sold;
    revenue = lhs.revenue + rhs.revenue;
    avg_price = (units_sold > 0) ? (revenue / units_sold) : 0.0;
    return Sales_data(lhs.isbn(), units_sold, avg_price)
}

Sales_data& Sales_data::operator+=(const Sales_data &data) {
    *this = *this + data;
    return *this;
}
