/*
What are the initial values, if any, of each of the following variables?
```
std::str global_str;
int global_int;
int main() {
    int local_int;
    std::string local_str;
}
```
*/

// the library string says that if we do not supply an initializer,
// then the resulting string is the empty string. so global_str and local_str are "".

// global_int is declared outside any function, so it is initialized to zero.
// local_int is declared inside a function, so its initial value is undefined.
