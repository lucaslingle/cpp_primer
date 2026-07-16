/*
Describe the differences in type deduction between decltype and auto.
Give an example where auto and decltype will deduce the same type,
and give an example where they will deduce differing types.
*/

// auto can be used to infer the type of a variable, but it must be initialized. 
// the initializer is used to infer the type.
// auto ignores references and top-level constants.
//
// decltype can be used to specify the type of a variable; it need not be initialized. 
// the type is inferred from an expression on which the decltype function is called.
// decltype preserves references and top-level constants.
// decltype can also be used on parenthesized variables (which are of reference type),
// and on assignment expressions (which are of reference type, 
// using the type on the left of the assignment).

// example of same:
// auto a1 = 1;
// decltype(1) a2 = 1;
// a1 has type int, a2 has type int.
//
// example of difference:
// int *const p = nullptr;
// auto q1 = p; 
// decltype(p) q2 = p;
// q1 is a null pointer, but is not a const ptr. 
// q2 is a null pointer, and is a const ptr.
//
// example of difference:
// int i = 0;
// int &r = i;
// auto x1 = r; 
// decltype(r) x2 = r;
// x1 is an int, its value is 0.
// x2 is an int&, its value is 0.
