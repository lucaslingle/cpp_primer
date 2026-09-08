/*
Rewrite the class representing a limited discount strategy, 
which you wrote for the exercises on p. 601, to inherit from `Disc_quote`.
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
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double price, std::size_t qty, double disc):
        Disc_quote(book, price, qty, disc) { }
    double net_price(std::size_t n) const override {
        if (n >= quantity)
            return (1 - discount) * n * price;
        else
            return n * price;
    }
};

class LimitedDiscount_quote : public Disc_quote {
public:
    LimitedDiscount_quote() = default;
    LimitedDiscount_quote(const std::string& book, double price, std::size_t qty, double disc):
        Disc_quote(book, price, qty, disc) { }
    double net_price(std::size_t n) const override {
        if (n <= quantity)
            return (1 - discount) * n * price;
        else
            return (1 - discount) * quantity * price + (n - quantity) * price;
    }
};
