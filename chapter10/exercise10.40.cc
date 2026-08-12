/*
What kind of iterators do you think copy requires?
What about reverse or unique?
*/

// copy: two input iterators for the source range,
//  and one output iterator for the destination.

// reverse: two bidirectional iterators for the source range

// unique: two random-access iterators for the source range
// update -- maybe if the dupes were written to the end, but theyre not.
// update -- unique only left-shifts values to eliminate duplicates.
// update -- whatever is left stays in the tail.
// update -- it performs the shifts using reading and writing iterators
//           utilizing the multi-pass capability of forward iterator.
