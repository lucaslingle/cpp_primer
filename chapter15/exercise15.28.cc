/*
Define a `vector` to hold `Quote` objects but put `Bulk_quote` objects
into that `vector`. Compute the total `net_price` of all elements in the `vector`.
*/

#include <iostream>
#include <string>
#include <cstddef>
#include <vector>

class Quote {
    public:
        Quote() = default;
        Quote(const std::string &book, double sales_price):
            bookNo(book), price(sales_price) { }
        std::string isbn() const { return bookNo; }
        virtual double net_price(std::size_t n) const { return n * price; }
        virtual ~Quote() = default;
    private:
        std::string bookNo;
    protected:
        double price = 0.0;
};

// double print_total(std::ostream& os, const Quote &item, std::size_t n) {
//     double ret = item.net_price(n);
//     os << "ISBN: " << item.isbn() 
//         << " # sold: " << n 
//         << " Total due: " << ret 
//         << std::endl;
//     return ret;
// }

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    // Bulk_quote() = default;
    // Bulk_quote(const std::string& book, double price, std::size_t qty, double disc):
    //     Disc_quote(book, price, qty, disc) { }
    double net_price(std::size_t n) const override {
        if (n >= quantity)
            return (1 - discount) * n * price;
        else
            return n * price;
    }
};

int main() {
    // will get sliced down, and base class will be net_price used.
    std::vector<Quote> qvec;
    qvec.push_back(
        Bulk_quote("The C++ Primer (Fifth Edition)", 69.99, 10, 0.25)
    );
    for (const auto &item : qvec)
        std::cout << item.net_price(11) << std::endl;

    return 0;
}