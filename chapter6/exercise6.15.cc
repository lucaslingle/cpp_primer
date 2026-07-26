/*
Explain the rationale for the type of each of find_char's parameters.
In particular, why is ```s``` a reference to const, but ```occurs``` a plain reference?
Why are these parameters references but the char parameter is not?
What would happen if we made ```s``` a plain reference?
What if we made ```occurs``` a reference to const? 
*/

int find_char(const string& s, char c, string::size_type &occurs);

// for s: passing a string by value would create a copy of the underlying character array
// which is expensive. the reference is to const as we are not modifying the string. 
// we could use a plain ref, but this is best practice.
// 
// for c: passing by value is cheap for char type, and we do not need to edit c.
//
// for occurs: we want to return the first index using the function return,
// and passing a reference allows us to indirectly report additional information
// by updating the value of ```occurs```. this is why it was made a reference.
