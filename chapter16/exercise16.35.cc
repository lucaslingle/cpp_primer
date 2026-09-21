/*
Which, if any, of the following calls are errors? 
If the call is legal, what is the type of `T`?
If the call is not legal, what is the problem?
```
template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);
double d;
float f;
char c;

(a) calc(c, 'c'); 
(b) calc(d, f);
(c) fcn(c, 'c');
(d) fcn(d, f);
```
*/

// (a) call is legal, as ordinary arg in position two (char 'c') 
// is promoted to int. T is deduced as char.

// (b) call is legal, as ordinary arg in position two (float f) 
// is subject to standard conversion. T is deduced as double.

// (c) call is legal, as template-typed arguments in positions one and two 
// (char c and char 'c') are the same type. T is deduced as char. 

// (d) call is illegal, as template-typed arguments in positions one and two
// (double d and float f) have conflicting deductions. 