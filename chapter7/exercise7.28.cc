/*
What would happen in the previous exercise if the return type of 
move, set, and display was Screen rather than Screen& ?
*/

// each function would return *this, which would dereference a pointer to the object.
// without a reference in the return type, the object would be copied during return,
// so function call statement would return a new object. 
//
// the first printout would be the updated object, 
// but the second printout would show the original screen, like so:
//
// XXXXX
// XXXXX
// XXXXX
// XXXXX
// #XXXX
//
// XXXXX
// XXXXX
// XXXXX
// XXXXX
// XXXXX
