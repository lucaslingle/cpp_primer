/*
What do upper_bound, lower_bound, and equal_range return
when you pass them a key that is not in the container?
*/

// they return an iterator to the location where 
// the key could be safely inserted to maintain key order. 
// if the key is larger than all elements of the associative container,
// the iterator will be the end iterator, one past the end of the container elements.
