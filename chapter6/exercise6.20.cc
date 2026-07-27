/*
When should reference parameters be references to const?
What happens if we make a parameter a plain reference 
when it could be a reference to const?
*/

// if not modifying the passed argument, 
// reference to const is always preferable to plain reference. 
// it has several advantages: it tells the reader the argument is not modified,
// it accepts literals, it accepts const objects, and it accepts objects that require conversion.
// 
// if you make a plain reference, literals, const objects and objects requiring conversion 
// cannot be passed as arguments.
