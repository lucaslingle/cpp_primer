/*
Assume that ```Numbered``` is a class with a default constructor that
generates a unique serial number for each object, which is stored in
a data member named ```mysn```. Assuming ```Numbered``` uses the
synthesized copy-control members and given the following function
```
void f(Numbered s) { cout << s.mysn << endl; }
```
what does the output of the following code produce?
```
Numbered a, b = a, c = b;
f(a); f(b); f(c);
```
*/

// it prints the serial number of a, three times.
