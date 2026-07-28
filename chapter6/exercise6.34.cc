/*
What would happen if the stopping condition in the factorial were
```
if (val != 0)
```

reference code:
```
int factorial(int val) {
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}
```
*/

// for negative numbers, the (val != 0) factorial will loop forever.
