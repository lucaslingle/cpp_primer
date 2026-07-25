/*
Explain each of the following loops. Correct any problems you detect.

(a)
```
do
    int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
while (cin);
```

(b)
```
do {
    // ...
} while (int ival = get_response());
```

(c)
```
do {
    int ival = get_response();
} while (ival);
```
*/

// (a) malformatted, should have curly braces to make compoiunt statement (block)
// for the do expression. once fixed, it will read two ints, sum them, print the sum.

// (b) it defines a variable in the while condition, which is disallowed.

// (c) it uses a local variable from the do expression in the while condition,
// which is out-of-scope.
