/*
What happens when a class template is instantiated?
*/

// The template parameters are bound to the template arguments,
// and a class is written at compile time based on the specified arguments.
// The compiler only instantiates (writes) the member functions and static data members 
// actually used by the program; all non-static data members are instantiated.