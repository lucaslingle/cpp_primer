/*
What would happen if we defined `sorted` as:
```
Foo Foo::sorted() const & {
    Foo ret(*this);
    return ret.sorted();
}
```
*/

// with an lvalue reference qualifier added,
// and the call to algorithm header sort removed,
// the function will enter an infinite recursion loop.

// from the main text, there is one other member function of `Foo`
// named sorted, but it is rvalue reference qualified, 
// so in the return statement above, overload resolution will not call it, 
// but rather call the lvalue reference qualified member function defined above. 

// to achieve the intended behavior, could do something like 
// ```return std::move(ret).sorted();```
