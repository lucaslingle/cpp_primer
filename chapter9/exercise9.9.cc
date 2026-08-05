/*
What is the difference between the begin and cbegin functions?
*/

// the begin member function of containers is overloaded.
// if the container is constant, it returns a const_iterator.
// if the container is nonconstant, it returns an iterator,
// which can be cast to const_iterator implicitly by assigning to a const_iterator variable.
//
// by contrast, cbegin always returns a const_iterator.
