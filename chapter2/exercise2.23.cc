/*
Given a pointer p, can you determine whether p points to a valid object?
If so, how? If not, why not?
*/

// in general it is not possible to determine that.
// for example, if int *p is uninitialized inside a function, its initial value is garbage, 
// but the bytes stored at the address it points to will correspond to some integer.
// but since the integer has nothing to do with the program being written, it is invalid. 
//
// best practice is to initialize all pointers to nullptr 
// if they cannot be immediately assigned to a valid object's address.
// this way, invalid pointer addresses can be identified by comparing with nullptr.
