/*
Explain whether defining these `Sales_data` conversion operators
is a good idea and whether they should be `explicit`.
*/

// Given that built-in conversions can be performed before and after
// converting via a user-defined conversion, adding these user-defined conversions
// adds a lot of room for error when the compiler inteprets an expression.
//
// This is especially the case because there is no single best definition
// for the conversion value. 
// E.g.: should converting to a double give revenue or price?
//
// It is better to design the class in a way that allows the user to 
// explicitly request the field they want. 

// If they are to be defined, marking these conversion operators as 
// explicit can limit unintentional conversions, though misunderstandings--such as
// whether conversion to double gives price or revenue--could remain.