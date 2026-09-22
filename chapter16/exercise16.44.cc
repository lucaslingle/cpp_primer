/*
Using the same three calls as in the first exercise (16.42), 
determine the types for `T` if `g`'s function parameter is declared as `T`,
not `T&&`. What if `g`'s function parameter is `const T&`?
*/

// in the first case, we have 
// `template <typename T> void g(T val);`
// so the types for T are
// (a) int
// (b) int (top-level const is dropped)
// (c) int

// in the second case, we have
// `template <typename T> void g(const T& val);`
// so the types for T are
// (a) int
// (b) int
// (c) int