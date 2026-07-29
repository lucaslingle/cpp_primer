/*
Add the combine and isbn members to the Sales_data class you wrote for the exercises 
in Sec 2.6.2 (p. 76) -- exercise 2.40 etc. 
*/

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo = "";
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data& combine(const struct Sales_data& elem) {
        units_sold += elem.units_sold;
        revenue += elem.revenue;
        return *this;
    }

    std::string isbn() const {
        return bookNo;
    }
  
};
