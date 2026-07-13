/*
What are the differences between int, long, long long, and short?
Between unsigned and a signed type? Between a float and a double?
*/

// A short guarantees at least 16 bits.
// An int guarantees at least 16 bits but is guaranteed to be at least as long as a short.
// A long guarantees at least 32 bits but is commonly the same bitwidth as an int.
//    In addition, a long is guaranteed to be at least as long as an int. 
// A long long guarantees at least 64 bits and it is guaranteed to be 
//    at least as long as a long.

// A signed type can store negative numbers. 
// An unsigned type can only store numbers greater than or equal to zero. 

// A float guarantees at least 6 significant digits, 
//     and is commonly implemented in 32 bits, yielding 7 significant digits.
// A double guarantees at least 10 significant digits, 
//     and is commonly implemented in 64 bits, yielding 16 significant digits.

