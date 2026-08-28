/*
What would happen if we defined a `HasPtr` move-assignment operator
but did not change the copy-and-swap operator? Write code to test your answer.
*/

// my assumption:
// what would happen is that the copy-and-swap operator would be used for
// copy assignment only, and the move-assignment operator would be used for moves,
// because the rvalue reference argument would be a better match 
// for a HasPtr we've called std::move on.

// what happened:
// ambiguity error.
// apparently the compiler likes pass-by-value of copy-and-swap
// just as well as rvalue reference of the move-assigmnent operator.
// this is despite having cast the assigned HasPtr to an rvalue reference with std::move.

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
    public: 
        HasPtr(const string &s = string()):
            ps(new string(s)), i(0) { }
        HasPtr(const HasPtr &h): 
            ps(new string(*h.ps)), i(h.i) 
        { 
            cout << "copy constructor" << endl;
        }
        HasPtr(HasPtr &&p) noexcept 
            : ps(p.ps), i(p.i) 
        { 
            cout << "move constructor" << endl;
            p.ps = nullptr; 
        }
        HasPtr& operator=(HasPtr rhs) { 
            cout << "copy-and-swap operator" << endl;
            swap(*this, rhs); 
            return *this; 
        }
        HasPtr& operator=(HasPtr &&rhs) noexcept {
            cout << "move-assignment operator" << endl;
            if (this == &rhs)
                return *this;
            delete ps;
            i = rhs.i;
            ps = rhs.ps;
            rhs.ps = nullptr;
            return *this;
        }
        ~HasPtr() {
            cout << "destructor" << endl;
            delete ps;
        }
    private:
        string *ps;
        int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    std::swap(lhs.ps, rhs.ps);
    std::swap(lhs.i, rhs.i);
}

int main() {
    cout << "initializing four HasPtrs via string constructor" << endl;
    HasPtr hp1 = HasPtr("Hello");
    HasPtr hp2 = HasPtr("World");
    HasPtr hp3 = HasPtr("Greetings");
    HasPtr hp4 = HasPtr("Planet");
    
    cout << "expecting a copy-assignment via copy-and-swap" << endl;
    hp1 = hp3;

    cout << "expecting a move assignment via move-assignment operator, not copy-and-swap" << endl;
    hp2 = std::move(hp4);

    return 0;
}