/*
Explain the differences between a parameter, a local variable, and 
a local static variable. Give an example of a function in which each might be useful.
*/

// a parameter is an input variable to a function.
// a local variable is a variable defined inside a function; 
//     as an automatic object, it will be destroyed when out of scope. 
// a local static variable is a variable defined inside a function,
//     whose value is retained across calls to the function.

// an example of a function that benefits from all three variable types
// is a function to identify the n-th smallest prime number. 
// we start with parameter (input variable) n, check a (static variable) vector to see if 
// the the result is memoized, and if not we loop over (local variable) primes until we find the n-th largest. 
