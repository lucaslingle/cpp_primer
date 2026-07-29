/*
Which one of the following declarations and definitions would you put
in a header? In a source file? Explain why.

(a) inline bool eq(const BigInt&, const BigInt&) { ... };
(b) void putValue(int *arr, int size);
*/

// (a) i would put in a header file because whenever we want to use it,
// we need the full definition to expand code inline, so 
// we cannot get by with a declaration in the header file alone. 
// 
// (b) placing this function def in a header would lead to problems. 
// when including the header in multiple C++ source files, the func def will appear
// in all of them, violating the one definition rule (odr). 
// for inline and constrexpr funcs, odr is relaxed; but not for ordinary functions.
