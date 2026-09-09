/*
Define the `Quote` and `Bulk_quote` copy-control members to do the 
same job as the synthesized versions. 

Give them and the other constructors print statements that identify 
which function is running.

Write programs using these classes and predict what objects will be
created and destroyed. 

Compare your predictions with the output and continue experimenting 
until your predictions are reliably correct.
*/

#include <iostream>
#include <string>
#include <cstddef>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    Quote(const Quote&);
    Quote(Quote&&) noexcept;
    Quote& operator=(const Quote&);
    Quote& operator=(Quote&&) noexcept;
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

Quote::Quote(const Quote& rhs) : 
    bookNo(rhs.bookNo), price(rhs.price) 
{
    std::cout << "Quote::Quote(const Quote& rhs)" << std::endl;
}

Quote::Quote(Quote&& rhs) noexcept : 
    bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) 
{
    std::cout << "Quote::Quote(Quote&& rhs)" << std::endl;
}

Quote& Quote::operator=(const Quote& rhs) {
    std::cout << "Quote::operator=(const Quote& rhs)" << std::endl;
    if (this == &rhs)
        return *this;
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
}

Quote& Quote::operator=(Quote&& rhs) noexcept {
    std::cout << "Quote::operator=(Quote&& rhs)" << std::endl;
    if (this == &rhs)
        return *this;
    bookNo = std::move(rhs.bookNo);
    price = rhs.price;
    return *this;
}

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) { }
    Bulk_quote(const Bulk_quote&);
    Bulk_quote(Bulk_quote&&) noexcept;
    Bulk_quote& operator=(const Bulk_quote&);
    Bulk_quote& operator=(Bulk_quote&&) noexcept;
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

Bulk_quote::Bulk_quote(const Bulk_quote& rhs) : 
    Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) 
{
    std::cout << "Bulk_quote::Bulk_quote(const Bulk_quote& rhs)" << std::endl;
}

Bulk_quote::Bulk_quote(Bulk_quote&& rhs) noexcept : 
    Quote(std::move(rhs)), quantity(rhs.quantity), discount(rhs.discount) 
{
    std::cout << "Bulk_quote::Bulk_quote(Bulk_quote&& rhs)" << std::endl;
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote& rhs) {
    std::cout << "Bulk_quote::operator=(const Bulk_quote& rhs)" << std::endl;
    if (this == &rhs)
        return *this;
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote&& rhs) noexcept {
    std::cout << "Bulk_quote::operator=(Bulk_quote&& rhs)" << std::endl;
    if (this == &rhs)
        return *this;
    Quote::operator=(std::move(rhs));  // named variables are lvalues
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
}

int main() {
    // Quote q1("0-201-78345-X", 50);
    // std::cout << "q1 created" << std::endl;
    // Quote q2 = q1;
    // std::cout << "q2 created via copy-construction" << std::endl;
    // Quote q3 = std::move(q1);
    // std::cout << "q3 created via move-construction" << std::endl;
    // q2 = q3;
    // std::cout << "q2 copy-assigned to q3" << std::endl;
    // q3 = std::move(q2);
    // std::cout << "q3 move-assigned to q2" << std::endl;

    Bulk_quote b1("0-201-78345-X", 50, 10, 0.1);
    std::cout << "b1 created" << std::endl;
    Bulk_quote b2 = b1;
    std::cout << "b2 created via copy-construction" << std::endl;
    Bulk_quote b3 = std::move(b1);
    std::cout << "b3 created via move-construction" << std::endl;
    b2 = b3;
    std::cout << "b2 copy-assigned to b3" << std::endl;
    b3 = std::move(b2);
    std::cout << "b3 move-assigned to b2" << std::endl;

    return 0;
}