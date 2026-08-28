/*
Explain in detail what happens in the assignments of the
`HasPtr` object on p. 541. In particular, describe step by step
what happens to the values of `hp`, `hp2` and the `rhs` parameter 
in the `HasPtr` assignment operator.

reference code:
```
class HasPtr {
public:
    // other constructors and copy control members ...

    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = nullptr; }
    HasPtr& operator=(HasPtr rhs)
        { swap(*this, rhs); return *this; }

    // other members as in p. 511 ...
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

// line 1
hp = hp2; // hp2 is an lvalue, copy constructor copies hps into rhs parameter

// line 2
hp = std::move(hp2); // hp2 is an rvalue reference, move constructor moves hp2 into rhs parameter
```
*/

// hp has a ps and an i value. so does hp2.
// hp2 is copied (line 1) or moved (line 2) into rhs argument of the assignment operator.
// the assignment operator calls swap(*this, rhs).
// both are implicitly converted to references at the call site.
// the swap function for HasPtrs runs.
// the ps values of rhs and hp are swapped.
// the i values of rhs and hp are swapped.
// the swap function returns.
// the assignment operator returns *this, which dereferences a pointer to hp.
// the rhs variable goes out of scope and its destructor runs.
// hp now contains the ps and i from hp2.

// in the first line, hp2 retains its value.
// in the second line, hp2.i stays the same and hp2.ps = nullptr.