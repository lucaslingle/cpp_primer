/*
What if any restrictions does using the version of resize 
that takes a single argument place on the element type?
*/

// the version of resize that takes a single element only allows specification 
// of the resized container size, and it value initializes the new elements, if any. 
// as a consequence, if this version of resize adds elements, it must be able to 
// be value-initialized. 
// 
// for example, if the element type is a class type, it must have a default initializer.
// if it does not, we use the other version of resize that takes an initial value 
// (class instance).
