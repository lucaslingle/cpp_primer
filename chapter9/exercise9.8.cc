/*
What type should be used to read elements in a list of strings?
To write them?
*/

// to read, we can use a list<string>::const_iterator, 
// and to write we can use a list<string>::iterator.
//
// the dereferenced elements of the iterators will be list<string>::const_reference
// and list<string>::reference type, respectively. 
// these are aliases for const string& and string&, respectively.

