/*
What is a "dangling else"? How are else clauses resolved in C++?
*/

// a dangling else is an else that is intended to be associated with an outer if
// lacking curly braces and containing an inner if.
// C++ will associate the else to the inner if instead of the outer one,
// contrary to what any whitespace indentation might seem to suggest.
