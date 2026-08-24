/*
Assume we want to define a version of StrBlob that acts like a value.
Also assume that we want to continue to use a shared_ptr so that our
StrBlobPtr class can still use a weak_ptr to the vector. 

Your revised class will need a copy constructor and a copy-assignment operator,
but will not need a destructor. Explain what the copy constructor and 
copy-assignment operator must do. Explain why the class does not need a destructor.
*/

// There is only one data member in StrBlob, namely a shared_ptr<vector<string>>
// so this is the only thing the copy-control member functions must handle.

// The copy constructor must copy the underlying vector pointed to by the 
// shared_ptr<vector<string>>, and make the new class' shared_ptr 
// point to the copied vector. 

// The copy-assignment operator must copy the underlying vector pointed to by the
// shared_ptr<vector<string>> in the RHS operand, then point the LHS operand's
// shared_ptr<vector<string>> to the copied vector. If the strong reference count
// of the LHS operand's previous shared_ptr<vector<string>> drops to zero,
// the underlying vector<string> will be destroyed. 

// The class does not need a destructor because it uses shared_ptr, 
// so if the strong reference count of the object pointed to on the heap
// drops to zero, the object will automatically be destroyed.
