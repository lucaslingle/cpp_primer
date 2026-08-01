/*
What would happen if we gave ```Screen``` a ```size``` member
defined as follows? Fix any problems you identify.
```
pos Screen::size() const {
    return height * width;
}
```
*/

// the member function screen is defined outside the class ```Screen```, 
// which is why the scope ```Screen::``` is needed. However, ```pos```
// is a type definition from within the screen class, and return types
// precede and are not in-scope for the class type, so they need an explicit scope:
//
// Screen::pos Screen::size() const {
//     return height * width;
// }