/*
The following assignment is illegal. Why? How would you correct it?

double dval; int ival; int *pi;
dval = ival = pi = 0;
*/

// the assignment operator is right-associative and requires that the left operand 
// be the same type as the right operand or convertible to it. 
// since pi is type int*, it cannot be converted to type int. 

// one way to fix:
//
// double dval; int ival; int *pi;
// pi = 0;
// dval = ival = 0;