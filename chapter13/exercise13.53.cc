/*
As a matter of low level efficiency, the HasPtr assignment operator is not ideal.
Explain why. Implement a copy assignment and move assignment operator for HasPtr
and compare the operations executed in your new move assign operator 
vs the copy-and-swap version.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::string;

class HasPtr {
    // friend void swap(HasPtr&, HasPtr&);
    public: 
        HasPtr(const string &s = string()):
            ps(new string(s)), i(0) { }
        HasPtr(const HasPtr &h): 
            ps(new string(*h.ps)), i(h.i) { }
        HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = nullptr; }
        // HasPtr& operator=(HasPtr rhs) { swap(*this, rhs); return *this; }
        HasPtr& operator=(const HasPtr &rhs) {
            if (this == &rhs)
                return *this;
            auto newps = new string(*rhs.ps);
            delete ps;
            i = rhs.i;
            ps = newps;
            return *this;
        }
        HasPtr& operator=(HasPtr &&rhs) noexcept {
            if (this == &rhs)
                return *this;
            delete ps;
            i = rhs.i;
            ps = rhs.ps;
            rhs.ps = nullptr;
            return *this;
        }
        ~HasPtr() {
            delete ps;
        }
    private:
        string *ps;
        int i;
};

// inline void swap(HasPtr &lhs, HasPtr &rhs) {
//     std::swap(lhs.ps, rhs.ps);
//     std::swap(lhs.i, rhs.i);
// }

// in original move-assignment operator, 
// the assigned HasPtr is moved into rhs via the move constructor.
// this involves an int move and a pointer move.
// then swap runs on *this and rhs.
// it calls std::swap on the ps, which runs three copy assignments on pointers.
// it calls std::swap on the i, which runs three copy assignments on ints.

// in the new move-assignment operator,
// the assigned HasPtr is bound to the rvalue reference rhs. 
// if it is self-assignment, no further operations occur and the function returns.
// otherwise, one pointer copy on ps occurs, and one int copy on i occurs.
// a second pointer copy occurs when rhs.ps is set to nullptr.
