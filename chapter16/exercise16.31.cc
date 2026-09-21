/*
Explain how the compiler might inline the call to the deleter if
we used `DebugDelete` with `unique_ptr`. 
*/

// The callable object instantiated from `DebugDelete` simply prints
// a fixed message about deleting a unique_ptr, and then calls `delete p`
// on the passed pointer `p`. This can be inlined by replacing every 
// call to ~unique_ptr with the corresponding actions. 
// 
// This is possible because the deleter is known at compile time due 
// to being a template parameter, which is in contrast to the situation 
// with `shared_ptr` deleters. 
