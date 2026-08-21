/*
Explain why the following declaration is illegal:
```
Sales_data::Sales_data(Sales_data rhs);
```
*/

// the expression defines a constructor for Sales_data,
// but when called this constructor would require the nonreference rhs 
// to be copy-initialized, and since it is a Sales_data object, 
// the compiler would look for a defined copy initializer for Sales_data.
// if the only thing is this function, it will trigger infinite recursion.
//
// even if a copy initializer ```Sales_data::Sales_data(Sales_data &rhs);```
// existed alongside this initializer, evaluating which overloaded constructor 
// to use might also require calling the copy-initializer, 
// though this is not explained in the main text.
