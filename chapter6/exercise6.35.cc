/*
In the call to ```factorial``` why did we pass val-1 instead of val--?
*/

// val-- would have been wrong,
// since it returns a copy of the value before decrementing, which is still val.
// in addition to being wrong mathematically, it would have led to an infinite loop.
//
// another question might be why we didn't use --val.
// the reason is there are two operands, and compiler determines the order of evaluation,
// so ```factorial(--val) * val``` may have undefined behavior. 
