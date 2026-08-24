/*
Give your class a < operator and define a vector of HasPtrs.
Give the vector some elements and then sort the vector.
Note when swap is called.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::string;

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr&, const HasPtr&);
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

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
    return (*lhs.ps < *rhs.ps) || ((*lhs.ps == *rhs.ps) && (lhs.i < rhs.i));
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "called: void swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
    std::cout << "info:   lhs: {*ps == " << *lhs.ps << ", i = " << lhs.i << "}" << std::endl;
    std::cout << "info:   rhs: {*ps == " << *rhs.ps << ", i = " << rhs.i << "}" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main() {
    std::vector<HasPtr> vec = {
        HasPtr("Hello"), HasPtr("World"), HasPtr("Greetings"), HasPtr("Planet")
    };
    std::sort(vec.begin(), vec.end());

    return 0;
}
