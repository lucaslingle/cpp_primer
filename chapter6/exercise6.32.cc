/*
Indicate whether the following function is legal. 
If so, explain what it does, and if not correct any errors then explain it. 
```
int &get(int *arry, int index) { return arry[index]; }
int main() {
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```
*/

// the ```get``` function is legal.
// it returns an int reference, which is an lvalue, and can be written to.
// this is also why it is valid for ```main``` to assign to the return value.
