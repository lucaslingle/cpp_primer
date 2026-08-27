/*
Distingish between an rvalue reference and an lvalue reference.
*/

// An rvalue reference is a special kind of reference that binds to to an rvalue 
// that is about to be destroyed. The syntax is `T &&rr = f()`.

// An lvalue reference is a plain reference to an lvalue (variable).
// The syntax is `T &r = x`. 

// One nuance: A const lvalue reference can also bind to an rvalue.
// The syntax is `const T &r = f()`. 
//
// The main advantage of rvalue references is that they are NOT const, 
// meaning we have write access to the rvalue that 
// is about to be destroyed, allowing us to modify it and reappropriate 
// relevant data members before the destructor runs. 
// This is the foundation of move semantics.
