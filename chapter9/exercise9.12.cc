/*
Explain the differences between the constructor that takes a container
to copy and the constructor that takes two iterators.
*/

// the constructor that takes a container to copy must receive a container
// of the same type (vector, list, deque, etc.) and containing the same element type.
//
// for the constructor that takes two iterators, there is no need for the container
// type to match (e.g., a vector can be constructed from iterators on a list),
// and in addition the element type need not be an exact match 
// as long as implicit conversion of element types is possible.
// lastly, iterators need not be from start and element after the end of a container,
// so it is possible to initialize a new container from a smaller slice of the whole.
