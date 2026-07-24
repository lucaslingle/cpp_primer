/*
Each of the programs in the highlighted text on page 184 (copied below) contains 
a common programming error. Identify and correct each error.

(a)
```
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++;
    case 'e': eCnt++;
    default: iouCnt++;
}
```

(b)
```
unsigned index = some_value();
switch (index) {
    case 1:
        int ix = get_value();
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ix] = index;
}
```

(c)
```
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break;
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
}
```

(d)
```
unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```
*/

// (a) there is no break statement in each case. also, maybe the default case 
// should not increment iouCount given that ch may not be a vowel at all. 

// (b) it is invalid to use a variable initialized in a case statement 
// inside another case. 

// (c) case statements must use int literals. 
// multiple cases cannot be combined via listing multiple int literals;
// they must be written as case 1: case 3: case 5: etc.
//
// in addition, oddcnt and evencnt are not the correct variable names, 
// but this is probably just a typo on the authors' part.

// (d) it is invalid to use variables as selectors in switch cases.
