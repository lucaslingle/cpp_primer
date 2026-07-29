/*
What is a candidate function? What is a viable function?
*/

// in the context of matching overloaded functions, a candidate function
// is any function with the same name as the called function 
// whose declaration is visible at the point of call.

// a viable function is any function whose parameter count 
// and types either matches perfectly or that can be made to 
// match via implicit type conversions. 