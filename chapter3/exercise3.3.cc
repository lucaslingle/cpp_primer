/*
Explain how whitespace characters are handled in the string 
input operator and in the getline function.
*/

// for the string input operator, it discards all leading whitespace 
// (spaces, tabs, newlines), and reads characters 
// until the next whitespace character is encountered, 
// which it leaves in the input buffer.

// for the getline function, it stores all characters up to (but excluding) 
// the first newline in the `line` argument, and it discards the newline from the input buffer.
// it returns a reference to the updated istream i.
