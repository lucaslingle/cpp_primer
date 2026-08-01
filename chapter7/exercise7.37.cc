/*
Using the version of Sales_data from this section, determine
which constructor is used to initialize each of the following
variables and list the values of the data members in each object.

```
Sales_data first_item(cin);

int main() {
    Sales_data next;
    Sales_data last("9-9999-99999-9");
}
```
*/

#include <iostream>
#include <string>

class Sales_data {
public:
    Sales_data(std::string s = ""): bookNo(s) { }
    Sales_data(std::string s, unsigned cnt, double price):
        bookNo(s), units_sold(cnd), revenue(price * cnt) { }
    Sales_data(std::istream &ist) { read(ist, *this) }
    // ...
}

// first_item(cin) - uses the istream initializer:
// values are {"", 0, 0.0}.

// Sales_data next - uses the default initializer Sales_data(std::string s = "") with default arg.
// values are {"", 0, 0.0}.

// Sales_data last("9-9999-99999-9") - uses the isbn-only initializer Sales_data(std::string s = "").
// values are {"9-9999-99999-9", 0, 0.0}.
