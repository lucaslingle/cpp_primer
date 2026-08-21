/*
What happens when we assign one StrBlob to another?
What about StrBlobPtrs?
*/

// This answer is an edit of the one for exercise 13.3.

// A StrBlob has no user-defined copy-assignment operator, which means
// it would use the synthesized copy-assignment operator.
//
// The synthesized copy-assignment operator assigns data members directly
// from the source object to the destination object.
//
// A StrBlob has only one data member, a shared_ptr<vector<string>>.
// It will be copied and assigned somewhere by the synthesized copy-assignment 
// operator, so its stored reference count will be incremented.

// A StrBlobPtr has no user-defined copy-assignment operator, which means
// it would use the synthesized copy-assignment operator.
//
// The synthesized copy-assignment operator assigns data members directly
// from the source object to the destination object.
//
// A StrBlobPtr has only two data members, of type size_t 
// and weak_ptr<vector<string>>, respectively. Upon running the
// the synthesized copy-assignment operator, the size_t variable will be assigned
// and the weak_ptr will be assigned. In addition, the resource to which
// weak_ptr points will have its weak reference count incremented.
