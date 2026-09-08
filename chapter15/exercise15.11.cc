/*
Add a virtual `debug` function to your `Quote` class hierarchy
that displays the data members of the respective classes.
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
        virtual void debug() const {
            std::cout << "bookNo: " << bookNo << std::endl;
            std::cout << "price: " << price << std::endl;
        }
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
        void debug() const override {
            Quote::debug();
            std::cout << "min_qty: " << min_qty << std::endl;
            std::cout << "discount: " << discount << std::endl;
        }
    protected:
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

class LimitedDiscount_quote : public Bulk_quote {
    public:
        LimitedDiscount_quote() = default;
        LimitedDiscount_quote(const std::string&, double, std::size_t, std::size_t, double);
        double net_price(std::size_t) const override;
        void debug() const override {
            Bulk_quote::debug();
            std::cout << "max_qty: " << max_qty << std::endl;
        }
    protected:
        std::size_t max_qty = 0;
};

LimitedDiscount_quote::LimitedDiscount_quote(
    const std::string& book, double p, std::size_t min_q, std::size_t max_q, double disc):
    Bulk_quote(book, p, min_q, disc), max_qty(max_q) 
{
}

double LimitedDiscount_quote::net_price(std::size_t cnt) const {
    if (cnt <= max_qty)
        return (1 - discount) * cnt * price;
    return (1 - discount) * max_qty * price + (cnt - max_qty) * price;
}

int main() {
    auto q = Quote("The C++ Primer (Fifth Edition)", 69.99);
    auto b = Bulk_quote("The C++ Primer (Fifth Edition)", 69.99, 5, 0.25);
    auto l = LimitedDiscount_quote("The C++ Primer (Fifth Edition)", 69.99, 5, 10, 0.25);
    // print_total(std::cout, q, 10);
    // print_total(std::cout, b, 10);
    // print_total(std::cout, l, 11);
    std::cout << "---------" << std::endl;
    q.debug();
    std::cout << "---------" << std::endl;
    b.debug();
    std::cout << "---------" << std::endl;
    l.debug();

    return 0;
}
