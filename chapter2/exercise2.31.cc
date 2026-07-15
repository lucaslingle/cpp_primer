/*
Given the declarations in the previous exercise, 
determine whether the following assignments are legal. 
Explain how the top-level or low-level const applies in each case.
*/

// r1 = v2;
// valid.
// r1 is int & type, and v2 is a const int, the top-level const qualifier is ignored on copy.

// p1 = p2;
// invalid.
// p1 is int * type, and p2 is const int * type, the low-level const qualifier makes the assignment invalid. 

// p2 = p1;
// valid.
// p2 is const int * type, and p1 is int * type, so the assignment is valid.

// p1 = p3;
// invalid. 
// p1 is int * type, and p3 is const int *const, so the top level const qualifier is ignored on copy,
// but the problem is that the low-level const qualifier cannot be. 

// p2 = p3; 
// valid. 
// p2 is const int * type, and p3 is const int *const, so the top level const qualifier is ignored on copy,
// and both pointers have low-level const qualifiers. 