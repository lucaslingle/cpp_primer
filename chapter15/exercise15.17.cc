/*
Try to define an object of type `Disc_quote` and see what errors 
you get from the compiler.
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

int main() {
    auto q = Quote("The C++ Primer (Fifth Edition)", 69.99);
    auto b = Bulk_quote("The C++ Primer (Fifth Edition)", 69.99, 10, 0.25);
    auto l = LimitedDiscount_quote("The C++ Primer (Fifth Edition)", 69.99, 10, 0.25);
    print_total(std::cout, q, 10);
    print_total(std::cout, b, 10);
    print_total(std::cout, l, 11);

    // this line wont run because it is an abstract class.
    // auto d = Disc_quote("The C++ Primer (Fifth Edition)", 69.99, 10, 0.25);
    // error is:
    /*
    exercise15.17.cc:78:14: error: allocating an object of abstract class type 'Disc_quote'
    78 |     auto d = Disc_quote("The C++ Primer (Fifth Edition)", 69.99, 10, 0.25);
        |              ^
    exercise15.17.cc:38:12: note: unimplemented pure virtual method 'net_price' in 'Disc_quote'
    38 |     double net_price(std::size_t) const = 0;
        |            ^
    1 error generated.
    */
}