/*
Define a variable that you initialize by calling begin() 
on the multiset named bookstore from p. 425. Write the variable's type 
without using auto or decltype.

reference code:
```
multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
```
*/

// in exercise 11.11 we saw that without decltype, the type of bookstore is
// multiset<Sales_data, bool(*)(const Sales_data&, const Sales_data&)>
//
// calling begin gives an iterator of type
// multiset<Sales_data, bool(*)(const Sales_data&, const Sales_data&)>::iterator
