/*
What would happen if the version of HasPtr in this section 
didn't define a destructor? What if HasPtr didn't define a copy constructor?
*/

// If HasPtr did not define a destructor, then the synthesized destructor 
// would be synthesized and used. The synthesized destructor only destroys
// data members and does not delete objects pointed to on the heap.
//
// As a result, the string pointed to by ps would not be deleted,
// and a memory leak would occur.

// If HasPtr did not define a copy constructor, then the synthesized copy constructor
// would be synthesized and used. The synthesized copy constructor only copies
// data members and does not copy objects pointed to on the heap.
//
// As a result, if one HasPtr instance were used to copy-initialize another,
// the first one to be destroyed would delete the string pointed to by ps
// (assuming the destructor is as defined in the main text), so the other
// instance would have a dangling pointer, and would also double-free the 
// heap memory pointed to, when the other HasPtr instance was destroyed. 
