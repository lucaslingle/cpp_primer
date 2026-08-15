/*
Does this class need const versions of push_back and pop_back?
If so, add them. If not, why aren't they needed?
*/

// push_back and pop_back modifies a vector pointed to by the class,
// so technically the class itself can be const and the const versions would run. 
// in this case, the shared_ptr is treated as top-level const, not low level.
//
// on the other hand, it asks if the class need these.
// the const versions would make a confusing interface for the user,
// who would expect a const member function not to alter the state of the class. 
