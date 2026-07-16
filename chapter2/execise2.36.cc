/*
In the following code, determine the type of each variable 
and the value each variable has when the code finishes. 
```
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```
*/

// a and b are ints.
// c is an int and is initialized to 3.
// d is an int& and is bound to a.
// ++c means that the int c is now 4.
// ++d means the int a is now 4, 
// and so the int& d is now 4 as well. 
//
// so a is 4, b is 4, c is 4, and d is 4.