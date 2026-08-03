/*
Why do you think vector defines its single-argument constructor as explicit,
but string does not?
*/

// if there is a function that expects a vector<T>, getting an int instead is wild.
// if there is a function that expects a string, getting a char* instead is reasonable.
