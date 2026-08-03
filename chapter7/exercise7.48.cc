/*
Assuming the Sales_data constructors are not explicit, what 
operations happen during the following declarations?
```
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```
What happens if the Sales_data constructors are explicit?
*/

// the first line defines a string value from a C-style string,
// using direct initialization.
//
// the second line defines a Sales_data object via direct initialization
// using the Sales_data(const string&) constructor, taking a string object.
//
// the third line defines a Sales_data object via direct initialization
// using the Sales_data(const string&) constructor, taking a C-string object,
// which is implicitly converted to a temporary string to which the argument is bound.

// if explicit: first line interp is same.
// if explicit: second line interp is same.
// if explicit: third line interp is same. proof: the code below works.

#include <iostream>
#include <string>

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

int main() {
    // if (std::cin) {
    //     Sales_data total = Sales_data(std::cin);
    //     while (std::cin) {
    //         Sales_data trans = Sales_data(std::cin);
    //         if (total.isbn() == trans.isbn())
    //             total.combine(trans);
    //         else {
    //             print(std::cout, total) << std::endl;
    //             total = trans;
    //         }
    //     }
    // } else {
    //     std::cerr << "No data?!" << std::endl;
    //     return -1;
    // }

    std::string null_isbn("9-999-99999-9");
    Sales_data item1(null_isbn);
    Sales_data item2("0-000-00000-0");

    print(std::cout, item1) << std::endl;
    print(std::cout, item2) << std::endl;

    return 0;
}
