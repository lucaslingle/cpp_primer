/*
Write your own version of the `Basket` class and use it to compute
prices for the same transactions as you used in the previous exercises.
*/

#include <iostream>
#include <string>
#include <cstddef>
#include <memory>
#include <set>
#include <utility>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;
    std::string isbn() const { return bookNo; }
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
    Bulk_quote(const std::string& book, double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) { }
    Bulk_quote* clone() const & override { return new Bulk_quote(*this); }
    Bulk_quote* clone() && override { return new Bulk_quote(std::move(*this)); }
    double net_price(std::size_t n) const override {
        if (n >= quantity)
            return (1 - discount) * n * price;
        else
            return n * price;
    }
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Basket {
public:
    void add_item(const Quote&);
    void add_item(Quote&&);
    double total_receipt(std::ostream&) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs, 
                        const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

void Basket::add_item(const Quote& sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote&& sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
}

double Basket::total_receipt(std::ostream& os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
        sum += print_total(os, **iter, items.count(*iter));
    os << "Total Sale: " << sum << std::endl;
    return sum;
}

int main() {
    Basket basket;
    for (int i = 0; i != 10; ++i)
        basket.add_item(Bulk_quote("The C++ Primer (Fifth Edition)", 69.99, 10, 0.25));
    basket.total_receipt(std::cout);
    
    return 0;
}