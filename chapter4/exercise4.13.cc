/*
What are the values of i and d after each assignment?

int i; double d;
(a) d = i = 3.5;
(b) i = d = 3.5;
*/

// (a) assignment is right-associative 
// and the type of the right operand is converted to the type of the left operand. 
// thus i = 3; d = 3.0;

// (b) same reasoning. obtain d = 3.5; i = 3;
