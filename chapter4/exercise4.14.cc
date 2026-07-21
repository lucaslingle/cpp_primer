/*
Explain what happens in each of the if tests:

if (42 = i)  // ...
if (i = 42)  // ...
*/

// if (42 = i)  // ...
// attempts to assign an lvalue i to the rvalue int literal 42. 
// the code is invalid and will not compile.
// this may be a typo and the user may have intended to write 42 == i instead. 

// if (i = 42)  // ...
// attempts to assign an rvalue int literal 42 to the lvalue i,
// and the result of the assignment is i, which is now 42. 
// this value is converted to a boolean and since it is nonzero, the boolean is true.
// the condition is thus always true regardless of the initial value of i.
// this may be a typo and the user may have intended to write i == 42 instead. 
