/*
Can Screen safely rely on the default versions of copy and assignment?
If so why and if not why not?
*/

// the default version of copy and assignment
// will copy and assign all data members as specified by their type.
// in our case, we have only data members of built-in type and of type string.
// both should perform deep copies for copy and assignment, which would be fine.
//
// no external resources are managed by the Screen class, so there is nothing else 
// to worry about during copy and assignment other than the data members.
