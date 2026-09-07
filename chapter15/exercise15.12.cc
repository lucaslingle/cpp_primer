/*
Is it ever useful to declare a member function as both `override` and `final`?
Why or why not?
*/

// this is not mentioned in the main text, but explicitly writing more than one of 
// virtual, override, and final is against C++ guidelines. 
//
// in a base class, using virtual and final together is unnecessary 
//     because the function could simply be non-virtual. 
//
// in a derived class, using final alone indicates an override 
//     and prevents further ones.
