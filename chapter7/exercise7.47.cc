/*
Explain whether the Sales_data constructor that takes a string
should be explicit. What are the benefits of making the constructor explicit?
What are the drawbacks?
*/

// i think it should be explicit. there aren't many reasonable places where
// the string-only constructor would be used. certainly it would not be useful
// to have as an automatic conversion in the class member function combine 
// or in the friend function print. 

// the drawback is that a string will not be automatically converted to 
// a Sales_data object, even if the type of a function parameter is Sales_data. 
