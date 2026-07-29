/*
Given the declarations for f from page 242:
```
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
```
list the viable functions if any for each of the following calls. 
Indicate which function is the best match, or if the call is illegal, 
whether there is no match or why the call is ambiguous. 

(a) f(2.56, 42);
(b) f(42);
(c) f(42, 0);
(d) f(2.56, 3.14);
*/

// (a) f(int, int) and f(double, double) are viable. 
// between these two, there is no pareto-optimal conversion path,
// so the call is ambiguous.

// (b) f(int) and f(double, double) are viable.
// between these two, f(int) requires no conversions for the first arg,
// while f(double, double) requires one. thus f(int) is the best match.

// (c) f(int, int) and f(double, double) are viable. 
// between these two, f(int, int) requires no conversions for the either arg,
// while f(double, double) requires one for each. thus f(int, int) is the best match.

// (d) f(int, int) and f(double, double) are viable. 
// between these two, f(double, double) requires no conversions for the either arg,
// while f(int, int) requires one for each. thus f(double, double) is the best match.
