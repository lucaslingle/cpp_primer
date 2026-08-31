/*
In exercise 7.40 you wrote a sketch of one of the following classes.
Decide what if any overloaded operators your class should provide.

(a) Book
(b) Date
(c) Employee
(d) Vehicle
(e) Object
(f) Tree
*/

// i implemented a Tree class as a binary search tree. 
// the main things i would include are operator==, operator!=.
//
// could also use operator< etc for posets if a tree defines an interval, 
// but that's a bit of a reach. 
//
// could also use operator% for truncation at int depth, but that's a reach too. 
//
// addition of two trees might interpreted as set union, to merge their elements.
// subtraction could be set subtraction. 
// would need to handle logic of duplicate elements somehow: 
//     go multiset and then remove all copies on subtract, 
//     or go set and dedupe on insert/union?
