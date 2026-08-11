/*
Explain the differences among the three kinds of insert iterators.
*/

// back_inserter: inserts elements at the end of the container by calling push_back.
// front_inserter: inserts elements at the beginning of the container by calling push_forward.
// inserter: takes not only the container as an argument but also an iterator to a position in it.
//    adds elements immediately before the position specified. 

// back_inserter and inserter preserves inserted elements' order, 
// while front_inserter reverses.