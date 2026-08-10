/*
In the call to ```equal``` on rosters, what would happen if both 
rosters held C-style strings, rather than library strings?
*/

// C-style strings are char* type, which means an equality comparison 
// would be performed on the stored addresses of the two pointers.
// even if they pointed to the same string value, they would not match.
// thus, ```equal``` would always return false for this container element type.
