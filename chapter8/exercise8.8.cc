/*
Revise the program from the previous exercise to append its output
to its given file. Run the program on the same output file at least 
twice to ensure that the data are preserved.
*/

#include <fstream>
#include <iostream>
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

int main(int argc, char *argv[]) {
    if (argc != 3)
        throw std::runtime_error("bad input format. expected: prog.o input_fname output_fname");

    std::ifstream inp(argv[1]);
    std::ofstream out(argv[2], std::ofstream::app);
    if (inp) {
        Sales_data total = Sales_data(inp);
        while (inp) {
            Sales_data trans = Sales_data(inp);
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(out, total) << std::endl;
                total = trans;
            }
        }
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}
