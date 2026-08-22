/*
Assume that we want ```HasPtr``` to behave like a value. That is, 
each object should have its own copy of the ```string``` to which the objects point.
We'll show the definitions of the copy-control members in the next section.
However, you already know everything you need to know to implement these members.
Write the ```HasPtr``` copy constructor and copy-assignment operator before reading on.
*/

// we already did this in exercisees 13.5, 13.8, and 13.11.
//
class HasPtr {
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
