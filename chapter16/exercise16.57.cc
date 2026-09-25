/*
Compare your variadic version of `errorMsg` to the `error_msg` function
from section 6.2.6 (p. 220). What are the advantages and disadvantages of each approach? 

reference code:
```
void error_msg(initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}
```
*/

// `error_msg` is simpler to write but requires all passed arguments to be 
// of the same type, namely string. it is possible to write template functions
// for the initializer list type, but the type must be shared by all arguments
// per call.

// `errorMsg` is able to handle arguments of different types within a single call.
// the main disadvantages are that the calls by `print` are made recursively,
// and require careful declaration ahead of time (or careful definition orders) 
// to have the correct behavior.
