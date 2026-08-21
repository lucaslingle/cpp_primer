/*
What is a destructor? What does the synthesized destructor do?
When is a destructor synthesized?
*/

// A destructor is a member function of a class that runs when a class 
// is destroyed. There can be only one destructor for a class type T, namely 
// ~T();
//
// The synthesized destructor has an empty function body, and 
// like all destructors after the function body runs, it 
// destroys data members of the class in the reverse
// of the order they were declared in. 
// Note that if a data member is a plain pointer to an object allocated on the heap,
// the destructor for the pointer is run, but this would not destroy or deallocate the object pointed to on the heap. 
//
// The synthesized destructor is synthesized for a class if it does not have 
// a user-defined destructor. 
