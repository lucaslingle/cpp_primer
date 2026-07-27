/*
Explain the behavior of the following function. 
If there are problems in the code, explain what they are and how you might fix them. 
```
void print(const int ia[10]) {
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```
*/

// the parameter type is interpreted as const int *, and the dimension is ignored.
// in general this function will accept arrays shorter or longer than 10 and will only 
// print the array faithfully if its dimension is exactly 10. 
//
// we can fix this by either:
// (1) using a special character inside the array to demarcate its end.
// (2) passing two iterators to the print function for its beginning and end.
// (3) including a size parameter for the user to specify the array length with.
// (4) (looking ahead) using templating to handle different lengths, 
//     and references to prevent arrays from having their types decayed to pointers.
