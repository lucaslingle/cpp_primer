/*
Explain how `make_shared` works.
*/

// `make_shared` is a template function from the standard library (<memory> header).
// it constructs a shared_ptr based on a passed template type T, 
// and stores a pointer to newly allocated object of type T on the heap.

// The object on the heap is instantiated using the arguments provided
// at the make_shared<T> function call site. 

// The most obvious way to implement `make_shared` would be to define a 
// variadic template with a distinguished template parameter T,
// followed by a parameter pack `Args` to be used with the function parameters.
// It could then use perfect forwarding to construct a new object of type T on 
// the heap like so: `new T(std::forward<Args>(args)...);`
