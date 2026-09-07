/*
Test your `print_total` function from exercise 15.3 by passing
both `Quote` and `Bulk_quote` objects to that function.
*/

#include <iostream>
#include <string>
#include <cstddef>

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

double print_total(std::ostream& os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() 
        << " # sold: " << n 
        << " Total due: " << ret 
        << std::endl;
    return ret;
}

class Bulk_quote : public Quote {
    public:
        Bulk_quote() = default;
        Bulk_quote(const std::string&, double, std::size_t, double);
        double net_price(std::size_t) const override;
    private:
        std::size_t min_qty = 0;  // minimum purchase for discount to apply
        double discount = 0.0;  // fractional discount to apply
};

Bulk_quote::Bulk_quote(const std::string& book, double p, 
                       std::size_t qty, double disc) :
    Quote(book, p), min_qty(qty), discount(disc) 
{
}

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

int main() {
    auto q = Quote("The C++ Primer (Fifth Edition)", 69.99);
    auto b = Bulk_quote("The C++ Primer (Fifth Edition)", 69.99, 5, 0.25);
    print_total(std::cout, q, 10);
    print_total(std::cout, b, 10);
    return 0;
}
