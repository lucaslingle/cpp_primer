/*
Given the following sketch of a class, write a copy constructor
that copies all the members. Your constructor should dynamically
allocate a new string and copy the object to which ps points,
rather than copying ps itself.
```
class HasPtr {
public: 
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0) { }
private:
    string *ps;
    int i;
}
```
*/

class HasPtr {
    public: 
        HasPtr(const string &s = string()):
            ps(new string(s)), i(0) { }
        HasPtr(const HasPtr &h): 
            ps(new string(*h.ps)), i(h.i) { }
    private:
        string *ps;
        int i;
}
