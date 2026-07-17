/*
In the binary search program on page 112, why did we write
``` mid = beg + (end - beg) / 2; ``` instead of ```mid = (beg + end) / 2;```?
*/

// beg and end are iterators. 
// iterators can be subtracted to produce diff_type variables, 
// and iterators and diff_type variables can be added to skip forward or backward.
// however, iterators cannot be added (e.g., to produce other iterators), 
// and in addition an iterator cannot be divided by an integer.
