/*
What difference would it make if we used a vector 
instead of a set to hold line numbers? 
Which approach is better? Why?
*/

// a vector has o(1) average push_back time.
// a set has o(logn) average insert time. (we always insert at the end tho.)
// vector seems better because the line nos are already ordered, 
// so the binary search is always a time waste.
//
// with a vec, have to ensure we don't insert more than once for duplicate words,
// so always have to check vec[vec.size()-1] != lineno before inserting.
