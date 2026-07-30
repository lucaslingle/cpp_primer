/*
Update your Sales_data class to hide its implementation.
The programs you've written to use Sales_data operations should continue to work.
Recompile those programs with your new class definition to verify that they still work.
*/

#include <iostream>
#include <string>

struct Sales_data;
std::istream &read(std::istream &ist, Sales_data &data);

struct Sales_data {
    friend std::istream &read(std::istream &ist, Sales_data &data);
    friend std::ostream &print(std::ostream &ost, const Sales_data &data);
    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
        double avg_price() const {
            return revenue / units_sold;
        }
    public:
        Sales_data() = default;
        Sales_data(const std::string &s): bookNo(s) { }
        Sales_data(const std::string &s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p*n) { }
        Sales_data(std::istream &ist) {
            read(ist, *this);
        }
        Sales_data &combine(const Sales_data &elem) {
            units_sold += elem.units_sold;
            revenue += elem.revenue;
            return *this;
        }
        std::string isbn() const {
            return bookNo;
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

int main() {
    if (std::cin) {
        Sales_data total = Sales_data(std::cin);
        while (std::cin) {
            Sales_data trans = Sales_data(std::cin);
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
