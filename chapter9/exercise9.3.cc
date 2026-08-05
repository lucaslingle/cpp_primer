/*
What are the constraints on iterators that form iterator ranges?
*/

// the iterators must refer to elements of the same container.
// in addition, the end iterator must be reachable by incrementing the begin iterator.
// these properties must be enforced by the programmer; they are not checked by the compiler.
