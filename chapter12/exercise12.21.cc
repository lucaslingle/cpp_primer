/*
We could have written StrBlobPtr's deref member function as follows:
```
string& deref() const {
    return *check(curr, "dereference past end")[curr]; 
}
```
Which version do you think is better and why?
*/

// well for one thing, indexing has a higher precedence than dereferencing.
// so the code above is not going to do what's intended.
//
// if the code is fixed as
// ```
// string& deref() const {
//     return (*check(curr, "dereference past end"))[curr]; 
// }
// ```
// it looks less readable than the version in the main text. 
