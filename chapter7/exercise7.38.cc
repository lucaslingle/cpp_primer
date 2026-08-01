/*
We might want to supply cin as a default argument to the constructor
that takes an istream&. Write the constructor declaration that uses 
cin as a default argument.
*/

#include <iostream>
#include <string>

class Sales_data {
    public:
        Sales_data(std::istream &ist = std::cin) { read(ist, *this) }
        Sales_data(std::string s, unsigned cnt, double price):
            bookNo(s), units_sold(cnd), revenue(price * cnt) { }
        // ...
}
