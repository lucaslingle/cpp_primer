/*
Using the variables in the previous exercise, 
which of the following assignments are legal? Explain why. 

(a) i = ic;
(b) p1 = p3;
(c) p1 = &ic;
(d) p3 = &ic;
(e) p2 = p1;
(f) ic = *p3;
*/

// (a) invalid. ic is an uninitialized const int and is invalid. it cannot be assigned. 
//
// (b) invalid. p1 is plain int * pointer, and p3 is a const int *const pointer. 
//     since p3 treats the value pointed to as a constant, it cannot be assigned to the plain pointer (Sec 2.4.2). 
//
// (c) invalid. ic is an uninitialized const int and is invalid. it cannot be addressed. 
//
// (d) invalid. ic is an uninitialized const int and is invalid. it cannot be addressed. 
//
// (e) valid. p1 is plain int * pointer, and p2 is an int *const pointer, which means the address stored by p2 cannot change.
//     however there is no restriction copying the address stored in p2 into p1. 
//
// (f) valid if used for initialization of ic. we would have const int ic = *p3, 
//     and p3 is an uninitialized pointer of type const int *const, 
//     which points to a segment of bytes somewhere that can be interpreted as an integer. 
//     it results in undefined behavior however because p3 might point to any value.
