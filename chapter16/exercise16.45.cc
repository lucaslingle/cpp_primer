/*
Given the following template, explain what happens if we call `g` on a 
literal value such as `42`. What if we call `g` on a variable of type `int`?
```
template <typename T> void g(T&& val) { vector<T> v; }
```
*/

// The int literal `42` is an rvalue, so `T` is inferred as `int`, 
// the function instantiates an object `vector<int> v` but does not use it.

// A varable of type `int` is an lvalue, so `T` is inferred as `int&`.
// the function cannot instantiate an object of type `vector<int&>` 
// and fails to compile. 
