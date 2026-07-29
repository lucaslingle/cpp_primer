/*
Write all four versions of f. 
Each function should print a distinguishing message.
Check your answers from the previous exercise.
If your answers were incorrect, study this section until you understand why.
*/

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

void f() {
    #ifndef NDEBUG
    cerr << "f()" << endl;
    #endif
}

void f(int) {
    #ifndef NDEBUG
    cerr << "f(int)" << endl;
    #endif
}
void f(int, int) {
    #ifndef NDEBUG
    cerr << "f(int, int)" << endl;
    #endif
}

void f(double, double = 3.14) {
    #ifndef NDEBUG
    cerr << "f(double, double)" << endl;
    #endif
}

int main() {
    // f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}
