/*
It is legal but redundant to refer to members through the this pointer.
Discuss the pros and cons of explicitly using the this pointer to access members.
*/

// if there is a global variable of the same name as a data member variable, 
// the latter will hide the global variable but for the reader 
// it can still be confusing if the variable has the same name.
// even if there is no global variable, the reader might not immediately know that.
// including ```this``` enables the reader to immediately know that a variable 
// is a data member of the class.
//
// the only downside to using ```this``` is that it makes the code 
// a bit more cluttered.
