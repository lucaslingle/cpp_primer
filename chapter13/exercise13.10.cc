/*
What happens when a StrBlob object is destroyed?
What about a StrBlobPtr?
*/

// A StrBlob has one data member, a shared_ptr<vector<string>> created via make_shared.
// When a StrBlob is destroyed, the synthesized destructor
// destroys all data members, meaning that the destructor for shared_ptr<vector<string>>
// is run. This destructor decrements the strong reference count for the object 
// pointed to on the heap, and if it reaches zero, it deletes the object on the heap,
// destroying it. Since the shared_ptr was created via make_shared, if the weak count 
// also reaches zero, the memory is deallocated.

// A StrBlobPtr has two data members, a size_t and a weak_ptr<vector<string>>.
// When a StrBlobPtr is destroyed, the synthesized destructor
// destroys all data members, meaning that the destructor for size_t and
// weak_ptr<vector<string>> is run. The destructor for the latter decrements
// the weak reference count for the vector<string> object on the heap. 
// By the time the strong reference count and weak reference count are both zero,
// the memory will be deallocated.