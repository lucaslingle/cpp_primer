/*
Determine whether the class you used in exercise 7.40
should have a conversion to bool. If so explain why,
and explain whether the operator should be explicit.
If not, explain why not.
*/

// in theory, we may like to test if the tree is empty,
// so this could be a good use-case for bool.

// i think marking it as explicit makes sense,
// because we do not want to allow inadvertent arithmetic conversions from bool
// if the tree appears in an arithmetic expression. 
//
// rather, we want the user to either explicitly cast to bool,
// or else use the tree in an expression such as a if/while/do/for condition,
// logical not/or/and operand, ternary condition, etc. 
