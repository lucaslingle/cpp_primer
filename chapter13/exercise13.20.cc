/*
Explain what happens when we copy, assign, or destroy objects
of our ```TextQuery``` and ```QueryResult``` classes from p. 484.
*/

// Based on the way TextQuery is defined in the main text, 
// it uses the default copy constructor and default copy-assign operator.
// Neither are deleted by the compiler.
// TextQuery has two data members. One is a shared_ptr<vector<string>>.
// The other is a map<string, shared_ptr<set<size_t>>>.
// Both will be copied and assigned to the left-hand object.
// This will increment the strong reference count for all shared pointers
// on the RHS of the copy/assign operation.

// Based on the way QueryResult is defined in the main text,
// it uses the default copy constructor and default copy-assign operator.
// Neither are deleted by the compiler.
// QueryResult has three data members. One is a string.
// One is a shared_ptr<vector<string>>. One is a shared_ptr<set<size_t>>.
// All will be copied and assigned to the left-hand object.
// This will increment the strong reference count for all shared pointers
// on the RHS of the copy/assign operation.
