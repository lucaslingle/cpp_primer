/*
What if we defined `sorted` as:
```
Foo Foo::sorted() const & { 
    return Foo(*this).sorted(); 
}
```
*/

// in that case, Foo(*this) would be copy-constructed
// and would be an rvalue, so the call to the rvalue reference qualified sorted()
// would work, and the sort would occur in-place on this copy.

// this achieves the exact same behavior as 
// the main text's lvalue reference qualified sorted(),
// where a named lvalue copy of *this is used for the sort and then returned by value.
