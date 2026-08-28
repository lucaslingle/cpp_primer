/*
Although `unique_ptrs` cannot be copied in Sec 12.1.5 (p. 471) we wrote
a `clone` function that returned a `unique_ptr` by value. 
Explain why that function is legal and how it works.
*/

// i assume it works because the unique_ptr has move constructors
// and move-assignment operators while not having copy constructors
// or copy-assignment operators.

// when the clone function returns, it yields an rvalue that can
// be used as an rvalue reference for either of these move operators.