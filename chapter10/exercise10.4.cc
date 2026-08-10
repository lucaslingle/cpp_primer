/*
Assuming v is a vector<double>, what if anything is wrong with calling
```accumulate(v.cbegin(), v.cend(), 0)```?
*/

// the third element is an int literal, and this parameter's type
// determines the type returned by accumulate. it will perform integer addition
// instead of double-precision floating point addition.
