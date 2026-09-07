/*
Given the following classes, explain each print function
```
class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};

class derived : public base {
public:
    void print(ostream &os) { print(os); os << " " << i; }
private:
    int i;
};
```
If there is a problem in this code how would you fix it?
*/

// in the base class `base`, virtual function `print` prints the data member `basename`.
// in the derived class `derived`, overridden function `print` calls itself
//    before attempting to print a space and the data member `i`.
//    an infinite loop occurs because the call `print(os)` 
//    should have been `base::print(os)`.
//
// the derived class should read

class derived : public base {
public:
    void print(ostream &os) override { base::print(os); os << " " << i; }
private:
    int i;
};