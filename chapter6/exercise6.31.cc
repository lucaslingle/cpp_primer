/*
When is it valid to return a reference? A reference to a const?
*/

// valid to return a reference to any preexisting object.
// invalid to return a reference to an object created locally within a function call.
//
// a reference to const is always allowed as a return type if a reference is.
// it just enforces that the object cannot be written to through the reference.
