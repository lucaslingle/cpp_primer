/*
Given the following definitions, 
```
char cval; int ival; unsigned int ui;
float fval; double dval;
```
identify the implicit type conversions, if any, taking place:
(a) cval = 'a' + 3;
(b) fval = ui - ival * 1.0;
(c) dval = ui * fval;
(d) cval = ival + fval + dval;
*/

// (a) 'a' is char, 3 is int literal. integral promotion makes the char an int,
// and assigning to cval converts back to char.

// (b) ival is int promoted to double, ui is promoted to double, 
// and assigning to fval converts to float.

// (c) ui is unsigned int promoted to float, 
// and assigning to dval converts to double.

// (d) addition is left-associative, so ival is int converted to float,
// (ival + fval) is float converted to double,
// and assigning to cval converts to char.
