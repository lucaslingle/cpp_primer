/*
Our StrBlobPtr does not define the copy constructor, 
assignment operator, or a destructor. Why is that ok?
*/

// StrBlobPtr contains only two data members, of types weak_ptr<vector<string>>
// and of type size_t. None of these involve heap allocations or anything else
// requiring a custom copy constructor, assignment operator, or destructor.
// The synthesized ones will do fine.