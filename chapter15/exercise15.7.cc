/*
Define a class that implements a limited discount strategy, which applies
a discount to books purchased up to a given limit. If the number of copies
exceeds that limit, the normal price applied to those purchased beyond the limit.
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
    protected:
        std::size_t max_qty = 0;
};

LimitedDiscount_quote::LimitedDiscount_quote(
    const std::string& book, double p, std::size_t min_q, std::size_t max_q, double disc):
    Bulk_quote(book, p, min_q, disc), max_qty(max_q) 
{
}

double LimitedDiscount_quote::net_price(std::size_t cnt) const {
    if (cnt < min_qty)
        return cnt * price;
    if (min_qty <= cnt && cnt <= max_qty)
        return cnt * price * (1 - discount);
    return max_qty * price * (1 - discount) + (cnt - max_qty) * price;
}

int main() {
    auto q = Quote("The C++ Primer (Fifth Edition)", 69.99);
    auto b = Bulk_quote("The C++ Primer (Fifth Edition)", 69.99, 5, 0.25);
    auto l = LimitedDiscount_quote("The C++ Primer (Fifth Edition)", 69.99, 5, 10, 0.25);
    print_total(std::cout, q, 10);
    print_total(std::cout, b, 10);
    print_total(std::cout, l, 11);
    return 0;
}
