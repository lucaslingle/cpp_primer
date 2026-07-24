/*
Correct the errors in each of the following code fragments.

(a).
```
if (ival1 != ival2)
    ival1 = ival2
else ival1 = ival2 = 0;
```

(b).
```
if (ival < minval)
    minval = ival;
    occurs = 1;
```

(c).
```
if (int ival = get_value())
    cout << "ival = " << ival << endl;
if (!ival)
    cout << "ival = 0\n";
```

(d).
```
if (ival = 0)
    ival = get_value();
```
*/

// (a) no semicolon on assignment ```ival1 = ival2```.
// (b) ```occurs = 1``` is not included in if-block.
// (c) ```ival``` is defined only within the first if.
// (d) ```ival = 0``` is always false, should be ```ival == 0```.
