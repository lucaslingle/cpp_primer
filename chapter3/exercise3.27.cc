/*
Assuming txt_size is a function that takes no arguments and returns
an int value, which of the following definitions are illegal? Explain why.

unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";
*/

// (a) invalid because buf_size is not a constexpr
// (b) valid because 4 * 7 - 14 is a constexpr
// (c) valid if txt_size() is declared as a constexpr (it can be).
// (d) invalid. string literal initialization of const array adds ending null byte, 
//     requiring 12 positions to spell fundamental\0.
