/*
Why don't list or array have capacity members?
*/

// vector and string have capacity because their implementation 
// requires storing all elements contiguously for constant-time index based lookup.
//
// list stores elements as nodes linked via pointers, 
// so there is no contiguity requirement. 
// 
// arrays have a fixed size known ahead of time, so there is no need 
// for a separate capacity quantity.
