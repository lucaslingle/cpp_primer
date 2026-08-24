/*
Write and test a swap function for your valuelike version of HasPtr.
Give your swap a print statement that notes when it is executed.
*/

#include <iostream>

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
    public: 
        HasPtr(const string &s = string()):
            ps(new string(s)), i(0) { }
        HasPtr(const HasPtr &h): 
            ps(new string(*h.ps)), i(h.i) { }
        HasPtr& operator=(const HasPtr &rhs) {
            auto new_ps = new string(*rhs.ps);
            delete ps;
            ps = new_ps;
            i = rhs.i;
            return *this;
        }
        ~HasPtr() {
            delete ps;
        }
    private:
        string *ps;
        int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "called: void swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
