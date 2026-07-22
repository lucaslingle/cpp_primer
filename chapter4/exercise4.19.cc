/*
Given that ptr points to an int, that vec is a vector<int>,
and that ival is an int, explain the behavior of each of these expressions.
Which if any are likely to be incorrect? Why? How might they be corrected?

(a) ptr != 0 && *ptr++
(b) ival++ && ival
(c) vec[ival++] <= vec[ival]
*/

// (a) checks ptr is nonnull, and if so, checks that its dereference is nonnull,
// and increments ptr. could be valid, depending on the usecase.

// (b) ival++ && ival uses logical AND so it evaluates the left operand first.
// this operand increments returns the an rvalue copy of original value of ival, 
// increments the lvalue ival, and ANDs with the new incremented value.
// both operands will be converted to boolean and will be true if nonzero,
// so the expression checks that ival and (ival+1) are both nonzero.
// could be valid, depending on the usecase.

// (c) invalid because either the left or right operand of <= could be evaluated first.
// if left is eval first, have vec[original_ival] <= vec[original_ival+1],
// if right is eval first, have vec[original_ival] <= vec[original_ival].
// in general, it will produce undefined behavior and is incorrect.
// it can be corrected by adding 1 manually and incrementing later.
