/*
Define your own reference-counted version of HasPtr.
*/

#include <string>
#include <memory>
#include <cstddef>
using std::string;
using std::size_t;

class HasPtr {
    public: 
        HasPtr(const string &s = string()):
            ps(new string(s)), i(0), use(new size_t(1)) { }
        HasPtr(const HasPtr &h): 
            ps(h.ps), i(h.i), use(h.use) { ++*use; }
        HasPtr& operator=(const HasPtr &rhs) {
            ++*rhs.use;
            if (--*use == 0) {
                delete ps;
                delete use;
            }
            ps = rhs.use;
            i = rhs.i;
            use = rhs.use;
            return *this;
        }
        ~HasPtr() {
            if (--*use == 0) {
                delete ps;
                delete use;
            }
        }
    private:
        string *ps;
        int i;
        size_t *use;
};
