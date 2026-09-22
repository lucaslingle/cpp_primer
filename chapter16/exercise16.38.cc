/*
When we call `make_shared` we have to provide an explicit template argument.
Explain why that argument is needed and how it is used. 
*/

// The function template has the form: `make_shared<T>(args)`.
// An explicit template argument is needed so that a new `T` can be allocated
// on the heap via the constructor that takes `args`. 
//
// Moreover abstractly, the return type of `make_shared` is `shared_ptr<T>`, 
// and `T` cannot be inferred from `args` alone. 