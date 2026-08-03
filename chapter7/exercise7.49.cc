/*
For each of the three following declarations of combine, explain what happens
if we call i.combine(s) where i is a Sales_data and s is a string.
(a) Sales_data &combine(Sales_data);
(b) Sales_data &combine(Sales_data&);
(c) Sales_data &combine(const Sales_data&) const;
*/

// (a) works fine. i.combine(s) makes a temporary object of type Sales_data
// from the string s, and passes it by value to the i member funtion combine.

// (b) does not work. i.combine(s) makes a temporary object of type Sales_data
// from the string s, and passes it by reference to the i member funtion combine,
// but a non-const reference parameter cannot be bound to a temporary rvalue argument. 

// (c) does not work. i.combine(s) makes a temporary object of type Sales_data
// from the string s, and passes it by reference to the i member funtion combine
// which would be okay since the argument type is a constant reference. 
// the problem is that the function is const, which requires that no data members of Sales_data are altered,
// (excepting those marked as mutable). Since we have not marked any data members as mutable, 
// the code will not compile. 
