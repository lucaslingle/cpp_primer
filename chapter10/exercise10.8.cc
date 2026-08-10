/*
We said that algorithms do not change the size of containers
over which they operate. Why doesn't the use of back_inserter invalidate this claim.
*/

// back_inserter is an insert iterator and is designed to mimic the behavior
// of an ordinary iterator. 
// the algorithm itself does not attempt to grow the container size,
// and is not aware that back_inserter is being used.
