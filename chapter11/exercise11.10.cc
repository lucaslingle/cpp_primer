/*
Could we define a map from a vector<int>::iterator to int?
What about from list<int>::iterator to int?
In each case, if not why not?
*/

// by default, a map uses the predicate < to compare keys.
// if keys had type vector<int>::iterator, then the predicate would work
// so long as all iterators came from the same vector.
// if the vectors can differ, the behavior of the predicate < is undefined. 

// for list<int>::iterator, the iterator type is a bidirectional iterator,
// not a random-access iterator, and it has no defined relation < built in.
// so it would not work unless a predicate were specified to the map.
