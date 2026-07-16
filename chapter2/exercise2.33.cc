/*
Using the variable definitions in this section, 
determine what happens in each of these assignments.
*/

// a = 42;
//
// we have
// int i = 0, &r = i;
// auto a = r;
// so a has type int.
// a = 42 just changes the stored value.

// b = 42;
//
// we have 
// const int ci = i, &cr = ci;
// auto b = ci;
// so b has type int.
// b = 42 just changes the stored value.

// c = 42;
//
// we have
// auto c = cr;
// cr is type const int&, and the top-level const is ignored.
// so c has type int.
// c = 42 just changes the stored value.

// d = 42;
// 
// we have
// auto d = &i;
// and i has type int, so d has type int *.
// d = 42 is an invalid assignment of an int to a pointer.

// e = 42;
// 
// we have
// auto e = &ci;
// and ci has type const int, so e has type const int *.
// e = 42 is an invalid assignment of an int to a pointer.

// f = 42;
//
// we have 
// const auto f = ci;
// ci has type const int, so f has type const int.
// f = 42 is invalid because f is top-level const. 

