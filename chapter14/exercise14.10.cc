/*
Define the behavior of the Sales_data input operator if given the following input:
(a) 0-201-99999-9 10 24.95
(b) 10 24.95 0-210-99999-9

reference code:
```
std::istream& operator>>(std::istream &ist, Sales_data &data) {
    double price;
    ist >> data.bookNo >> data.units_sold >> price;
    if (ist)
        data.revenue = price * data.units_sold;
    else
        data = Sales_data();
    return ist;
}
```
*/

// (a) in this case all the inputs can be converted correctly:
// bookNo is string, units_sold is unsigned, and price is double,
// and the Sales_data object is populated successfully.

// WRONG ANSWER I GAVE:
// (b) in this case the first input is successfully converted to string,
// and the second input is is successfully converted to unsigned via truncation,
// and the third input is NOT successfully converted to type double,
// so the failbit will be set. in this case an empty Sales_data is created
// by operator>>

// CORRECT ANSWER:
// (b) The stream will not fail, the failbit will not be set, 
// and the Sales_data object will not be reset to default.
//
// Here is exactly how the stream parses the input 10 24.95 0-210-99999-9:
//
// ist >> data.bookNo (string): The stream reads characters until the first whitespace. 
//     It consumes 10. data.bookNo becomes the string "10".
//
// ist >> data.units_sold (unsigned): The stream looks at 24.95. 
//     It reads the 2 and the 4, but stops at the . because a decimal point is 
//     not a valid character for an integer. data.units_sold becomes 24.
//
// ist >> price (double): The stream pointer is currently sitting exactly at .95. 
//     It reads this as a floating-point number and stops at the next whitespace. 
//     price successfully becomes 0.95.
