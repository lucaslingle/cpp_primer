/*
class LongDouble {
public:
    LongDouble(double db=0.0): ld(static_cast<long double>(db)) { }
    operator double() { return static_cast<double>(ld); }
    operator float() { return static_cast<float>(ld); }
private:
    long double ld;
};

int main() {
    LongDouble ldObj(42.0);
    // int ex1 = ldObj;
    float ex2 = ldObj;
}
*/

#include <iostream>

class C {
friend void manip(const C&);
friend void manip2(const C&);
public:
    C(int val): stored(val) { }
private:
    int stored;
};

class D {
friend void manip(const D&);
public:
    D(int val): stored(val) { }
private:
    int stored;
};

class E {
friend void manip2(const E&);
public:
    E(double val): stored(val) { }
private:
    double stored;
};

void manip(const C& cobj) {
    std::cout << cobj.stored << std::endl;
}
void manip(const D& dobj) {
    std::cout << dobj.stored << std::endl;
}

void manip2(const C& cobj) {
    std::cout << cobj.stored << std::endl;
}
void manip2(const E& eobj) {
    std::cout << eobj.stored << std::endl;
}

int main() {
    //manip(10);
    manip2(10);
    return 0;
}