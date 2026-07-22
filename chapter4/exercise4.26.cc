/*
In our grading example in this section what would happen 
if we used unsigned int as the type for quiz1?
*/

// the c++ standard only guarantees 16 bits for ints, even if 32 bit ints are common.
// so there could be portability problems. 
// 
// as one example, the expression to represent the bitmask for student 27, 
// obtained via 1 << 27 would have undefined behavior on a machine with 16-bit ints,
// as the shift amount is not strictly less than the number of bits of the left operand. 
