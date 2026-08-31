/*
What if anything is wrong with the following Sales_data input operator?
What would happen if we gave this operator the data in the previous exercise?
```
istream& operator>>(istream& in, Sales_data& s) {
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}
```
*/

// giving exercise 14.10 (a) data would work.

// giving exercise 14.10 (b) data would work, 
// but the data would be corrupted, same as in the previous exercise. 
