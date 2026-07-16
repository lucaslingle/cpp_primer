/*
Assignment is an example of an expression that yields a reference type.
The type is a reference to the type of the left-hand operand. That is, if i is an int, 
the type of the expression i = x is int&. Using that knowledge, determine the type
and value of each variable in this code:
```
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```
*/

// a and b are ints initialized to 3 and 4.
// c is an int initialized to 3.
// a = b in the decltype means that a is now 4.
// d is an int& bound to a, which is 4.
// thus a is 4, b is 4, c is 3, and d is 4.