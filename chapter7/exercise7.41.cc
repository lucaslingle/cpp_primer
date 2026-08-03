/*
Rewrite your own version of the Sales_data class to use delegating constructors.
Add a statement to the body of each of the constructors that prints a message 
whenever it is executed. Write declarations to construct a Sales_data in 
every way possible. Study the output until you are certain you understand the order
of execution among delegating constructors. 
*/

#include <iostream>
#include <string>

struct Sales_data;
std::istream &read(std::istream &ist, Sales_data &data);

struct Sales_data {
    friend std::istream &read(std::istream &ist, Sales_data &data);
    // friend std::ostream &print(std::ostream &ost, const Sales_data &data);
    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
        double avg_price();
    public:
        Sales_data(const std::string &s, unsigned n, double p):
            bookNo(s), units_sold(n), revenue(p*n) { 
                std::cout << "Sales_data(const std::string &s, unsigned n, double p)" << std::endl;
            }
        Sales_data():
            Sales_data("", 0, 0.0) { 
                std::cout << "Sales_data()" << std::endl;
        }
        Sales_data(const std::string &s): 
            Sales_data(s, 0, 0.0) { 
                std::cout << "Sales_data(const std::string &s)" << std::endl;
            }
        Sales_data(std::istream &ist):
            Sales_data() {
                std::cout << "Sales_data(std::istream &ist)" << std::endl;
                read(ist, *this);
        }
        // Sales_data &combine(const Sales_data &elem) {
        //     units_sold += elem.units_sold;
        //     revenue += elem.revenue;
        //     return *this;
        // }
        // std::string isbn() const {
        //     return bookNo;
        // }
};

// inline double Sales_data::avg_price() const {
//     return revenue / units_sold;
// }

std::istream &read(std::istream &ist, Sales_data &data) {
    double price;
    ist >> data.bookNo >> data.units_sold >> price;
    data.revenue = price * data.units_sold;
    return ist;
}

// std::ostream &print(std::ostream &ost, const Sales_data &data) {
//     ost << data.bookNo << " " 
//         << data.units_sold << " " 
//         << data.revenue << " "
//         << data.avg_price();
//     return ost;
// }

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

    std::cout << "a" << std::endl;
    Sales_data a = Sales_data("hello-world", 123, 45.00);

    std::cout << "\nb" << std::endl;
    Sales_data b = Sales_data();

    std::cout << "\nc" << std::endl;
    Sales_data c = Sales_data("some-isbn");

    std::cout << "\nd" << std::endl;
    Sales_data d = Sales_data(std::cin);

    return 0;
}
