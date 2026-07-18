/*
Given that p1 and p2 point to elements of the same array, 
what does the following code do? Are there any values of p1 or p2
that make this code illegal?

p1 += p2 - p1;
*/

// the code takes the ptrdiff_t quantity required to go from p1 to p2,
// and adds it to p1. the results is that the address contained in the p2 pointer
// is written into p1. given that p1 and p2 point to elements of the same array,
// there are no values that make the code invalid.
