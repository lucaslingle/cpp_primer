/*
What are the advantages of an unordered container 
as compared to the ordered version of that container?
What are the advantages of the ordered version?
*/

// - an unordered container does not have to maintain ordering among keys,
//   and can be faster when properly tuned. 
// - average case performance is O(1) for search, insert, delete. 
//   worst case is O(N) if all keys collide.
// - requires a hash function and a == predicate.
// - offers local iterators like c.begin(n), c.end(n) per hash code n.
//
// - an ordered container does have to maintain ordering among keys,
//   and does not require any tuning. 
// - average and worst case performance is O(logN)
//   for search, insert, delete. 
// - requires only a < predicate.
// - offers iterator range functions like lower_bound, upper_bound, equal_range.
