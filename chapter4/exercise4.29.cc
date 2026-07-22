/*
Predict the output of the following code and explain your reasoning.
Now run the program. Is the output what you expected? If not figure out why.
```
int x[10]; int *p = x;
cout << sizeof(x) / sizeof(*x) << endl;
cout << sizeof(p) / sizeof(*p) << endl;
```
*/

// output will be 10 for first line.
// assuming int-valued addresses, second line will be 1.

#include <iostream>
using std::cout;
using std::endl;

int main() {
    int x[10]; int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;
    return 0;
}

// on my machine, turns out pointers have a larger size than ints.
// second line was 2.
