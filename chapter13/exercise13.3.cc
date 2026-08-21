/*
What happens when we copy a StrBlob? What about a StrBlobPtr?
*/

// A StrBlob has no user-defined copy constructor, which means
// it would use the synthesized copy constructor.
//
// The synthesized copy constructor copies data members directly
// from the source object to the destination object.
//
// A StrBlob has only one data member, a shared_ptr<vector<string>>.
// It will be copied, and as it is assigned somewhere by the 
// synthesized copy constructor, its stored reference count will be incremented.

// A StrBlobPtr has no user-defined copy constructor, which means
// it would use the synthesized copy constructor.
//
// The synthesized copy constructor copies data members directly
// from the source object to the destination object.
//
// A StrBlobPtr has only two data members, of type size_t 
// and weak_ptr<vector<string>>, respectively. Upon assignment via
// the synthesized default constructor, the size_t variable will be copied
// and the weak_ptr will be copied. In addition, the resource to which
// weak_ptr points will have its weak reference count incremented.
