/*
Explain why the calls to swap inside swap(HasPtr&, HasPtr&) do not 
cause a recursion loop.

reference code:
```
class HasPtr {
    friend void swap(HasPtr&, HasPtr&)
    // other members as in p. 511
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
```
*/

// the function swap is overloaded.
// the versions called inside are for pointers and ints, not HasPtrs.
