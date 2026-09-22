/*
Using the function defined in the previous exercise, what would 
the template parameter of `g` be, if we called `g(i = ci)`?
*/

// The expression `i = ci` assigns the value stored by `ci`
// to `i` and evaluates to the lvalue `i`, which has type `int`. 
// in this case the template parameter would be `int&`. 