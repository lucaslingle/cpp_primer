/*
Determine the type of `T` and `val` in each of the following calls:
```
template <typename T> void g(T&& val);
int i = 0; const int ci = i;
(a) g(i);
(b) g(ci);
(c) g(i * ci);
```
*/

// (a) `i` is an lvalue, so type `T` is `int&`, 
// and `val` is `int&` due to reference collapsing.

// (b) `ci` is a const lvalue, so type `T` is `const int&`,
// and `val` is `const int&` due to reference collapsing. 

// (c) `i * ci` is an rvalue, so type `T` is `int`,
// and `val` is `int&&`. 