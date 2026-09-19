/*
For each labeled statement explain what, if any, instantiations happen.
If a template is instantiated, explain why; if not, explain why not.
```
template <typename T> class Stack { };
void f1(Stack<char>);                        // (a)
class Exercise {
    Stack<double> &rsd;                      // (b)
    Stack<int> si;                           // (c)
};
int main() {
    Stack<char> *sc;                         // (d)
    f1(*sc);                                 // (e)
    int iObj = sizeof(Stack<string>);        // (f)
}
```
*/

// The compiler only instantiates a class template
// when it needs a complete type--meaning it 
// needs to know the size, memory layout, or members of the class. 

// With that in mind, here are my answers:
//
// (a) no, since no complete type of an argument is needed in a function declaration.
// (b) no, since no complete type is needed since `rsd` is a reference.
// (c) yes, since a complete type is needed since `si` is contained in Exercise. 
// (d) no, since no complete type is needed for a pointer `sc` to that type.
// (e) yes, since dereferencing `sc` and passing by value requires copying, 
//     the members must be known and a complete type is needed.
// (f) yes, since a complete type is needed for the size of `Stack<string>` 
//     to be known. 
