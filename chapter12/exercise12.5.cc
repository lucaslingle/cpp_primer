/*
We did not make the constructor that takes an initializer list ```explicit```.
Discuss the pros and cons of this design choice.
*/

// Single-argument constructors in C++ are by default allowed to serve as
// conversion constructors, meaning that a variable of StrBlob type could be 
// created via implicit conversion from a curly-braced list, 
// using the conversion constructor.
// 
// Marking the constructor as explicit prevents it from being used as a 
// conversion constructor, which can improve readability of user code, 
// and prevent accidental conversions. 