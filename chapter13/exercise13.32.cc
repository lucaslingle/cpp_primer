/*
Would the pointerlike version of HasPtr benefit from defining a swap function?
If so, what is the benefit? If not, why not?
*/

// in the pointerlike version, everything is a built-in type,
// and there is no exception safety argument to worry about, 
// which is a key reason for the copy-and-swap idiom.
//  
// one could argue it could still be useful to simplify the copy assignment operator.
// that way, everything could be done via copy and swap.
// however, this moves code from assignment operator to swap. not really worth it. 
