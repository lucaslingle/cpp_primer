/*
In what ways does an overloaded operator differ from a built-in operator?
In what ways are overloaded operators the same as built-in operators?
*/

// overloaded operators can be defined to execute any function of their inputs,
// and can have any return type. at least one operand of an overloaded operator
// must be of class type. unlike some built-in operands, overloaded operands 
// do not promise an order of operand evaluation,
// and do not provide any short-circuiting capabilities.

// overloaded operators have the same arity, associativity, and precendence as their 
// built-in counterparts.