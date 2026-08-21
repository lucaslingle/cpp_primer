/*
Add a destructor to your HasPtr class from exercises 13.5 and 13.8.
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
        ~HasPtr() {
            delete ps;
        }
    private:
        string *ps;
        int i;
};
