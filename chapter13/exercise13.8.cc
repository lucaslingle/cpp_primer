/*
Write the assignment operator for the HasPtr class from exercise 13.5.
As with the copy constructor, your assignment operator should copy
the object to which ps points.
*/

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
    private:
        string *ps;
        int i;
};
