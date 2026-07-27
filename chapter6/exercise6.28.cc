/*
In the second version of ```error_msg``` that has an ```ErrCode```
parameter, what is the type of ```elem``` in the for loop?

Reference code:
```
void error_msg(ErrCode e, initializer_list<string> il) {
    cout << e.msg() << ": ";
    for (const auto &elem : il)
        cout << elem << " ";
    cout << endl;
}
```
*/

// the type is const string &.