/*
Write code to test your answers in the previous two exercises.
*/

#include <iostream>
#include <string>

class Base {
public:
    void pub_mem() { std::cout << "successfully called pub_mem()" << std::endl ; }
    void memfcn(Base &b) { b = *this; }
protected:
    int prot_mem = 0;
private:
    char priv_mem = 'a';
};

struct Pub_Derv : public Base {
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
    // void memfcn(Base &b) { b = *this; } // uncomment to see illegal as in ex. 15.19
};

struct Derived_from_Protected : public Prot_Derv {
    void memfcn(Base &b) { b = *this; }
};

int main() {
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base *p = &d1;
    // p = &d2;       // uncomment to see illegal as in ex. 15.18
    // p = &d3;       // uncomment to see illegal as in ex. 15.18
    p = &dd1;      
    // p = &dd2;      // uncomment to see illegal as in ex. 15.18
    // p = &dd3;      // uncomment to see illegal as in ex. 15.18

    return 0;
}