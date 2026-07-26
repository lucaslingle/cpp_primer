/*
Indicate which of the following functions are in error and why.
Suggest how you might correct the problem.

(a) int f() {
    string s;
    ...
    return s;
}

(b) f2(int i) { ... }
(c) int calc(int v1, int v1) { ... }
(d) double square(double x) return x * x;
*/

// (a) seems fine. you cannot return an array or a function from a function,
//     but C++ strings are not C-style strings (character arrays); it should be fine.
// (b) no return type specified.
// (c) repeated parameter name v1.
// (d) functions are required to have a statement block with curly braces.
