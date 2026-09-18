/*
What if any are the differences between a type parameter that is 
declared as a `typename` and one that is declared as a `class`?
When must `typename` be used?
*/

// In C++11, there is no difference between type parameters that
// are declared with `typename` versus those declared with `class`.
//
// The keyword `typename` is separately used in the context of class templates
// for distinguishing type members from static members.
// Both may use the scope operator on a templated class name, and the compiler
// needs to know when reading the class template which kind of entity
// it is parsing, and this won't be otherwise known until instantiation.
// In this case, the keyword `typename` preceeds the dependent type, not `class`. 
