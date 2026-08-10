/*
Rewrite exercise 10.12 from p. 387 to use a lambda in the call to ```sort```
instead of the ```compareIsbn``` function.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

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

// bool compare_isbn(const Sales_data &d1, const Sales_data &d2) {
//     return d1.isbn() < d2.isbn();
// }

int main(int argc, char *argv[]) {
    // if (argc != 3)
    //     throw std::runtime_error("bad input format. expected: prog.o input_fname output_fname");

    // std::ifstream inp(argv[1]);
    // std::ofstream out(argv[2], std::ofstream::app);
    // if (inp) {
    //     Sales_data total = Sales_data(inp);
    //     while (inp) {
    //         Sales_data trans = Sales_data(inp);
    //         if (total.isbn() == trans.isbn())
    //             total.combine(trans);
    //         else {
    //             print(out, total) << std::endl;
    //             total = trans;
    //         }
    //     }
    // } else {
    //     std::cerr << "No data?!" << std::endl;
    //     return -1;
    // }

    std::vector<Sales_data> vec = {
        Sales_data("123-456-789", 10, 25.00),
        Sales_data("999-888-777", 5, 11.00),
        Sales_data("123-456-789", 1, 33.00),
        Sales_data("555-555-555", 7, 10.00),
        Sales_data("999-888-777", 3, 20.00),
    };

    std::stable_sort(vec.begin(), vec.end(), 
                     [](const Sales_data &d1, const Sales_data &d2) 
                     { return d1.isbn() < d2.isbn(); });
    for (const auto &d : vec)
        print(std::cout, d) << std::endl;

    return 0;
}
