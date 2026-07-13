/*
Explain the key differences between pointers and references.
*/

// a reference is immutably bound to one object.
// it must be initialized, e.g., int i = 0; int &r = i.
// the object can be assigned to by assigning directly to the reference, e.g., r = 123;
// the object can be used in an expression by naming the reference, e.g., 2 * r;
// a reference itself is not an object and has no accessible address.

// a pointer is a memory address for a given type of object.
// the memory address stored in a pointer can be zero (nullptr), 
//     or the address of an object, 
//     or the address immediately after an object, 
//     or undefined if the pointer is not initialized and is inside in a block.
// the address stored by a pointer can change, e.g., int *p = nullptr; p = &i.
// the object can be assigned to via dereferencing, e.g., *p = 3.14;
// the object can be used in expressions via dereferencing, e.g., *p + 0.01;
// the pointer itself is an object and has an address, e.g., &p;
