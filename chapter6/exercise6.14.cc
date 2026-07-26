/*
Give an example of when a parameter should be a reference type.
Give an example of when a parameter should not be a reference.
*/

// a longest common substring function might like to take two const string references 
// as inputs in case the strings are large.

// the factorial function should not use an int reference as a parameter;
// it suffices to pass by value, because the int is not expensive to copy, 
// can be copied, and is not intended to be updated by the function.
