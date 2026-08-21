/*
How many destructor calls occur in the following code fragment?
```
bool fcn(const Sales_data *trans, Sales_data accum) {
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}
```
*/

// Sales_data destructors are called three times, for accum, item1, and item2.
// In general, the TOTAL number of ALL destructor calls is higher, however.

// 1. ```Sales_data accum``` destructor.
// a Sales_data object is constructed as an argument at the start of the function call.
// when the function returns, its destructor is run. 
// since it has no user-defined destructor, the synthesized destructor is run.
//
// 2. the synthesized destructor for Sales_data accum
// destroys the data members bookNo (string). as for units_sold (unsigned), and revenue (double),
// they built-in types and have no destructor. 

// 3. item1 destructor.
// 
// 4. the synthesized destructor for Sales_data item1
// destroys the data members bookNo (string). as for units_sold (unsigned), and revenue (double),
// they built-in types and have no destructor. 

// 5. item2 destructor.
//
// 6. the synthesized destructor for Sales_data item2
// destroys the data members bookNo (string). as for units_sold (unsigned), and revenue (double),
// they built-in types and have no destructor. 

// 7. item1.isbn() destructor.
// 8. item2.isbn() destructor.
