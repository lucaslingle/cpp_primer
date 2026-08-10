/*
Determine if there are any errors in the following programs 
and if so correct the error(s).

(a)
```
vector<int> vec; list<int> lst; int i;
while (cin >> i)
    lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());
```

(b)
```
vector<int> vec;
vec.reserve(10);
fill_n(vec.begin(), 10, 0);
```
*/

// (a) vec has length zero, vec is expected to have length at least lst.size(). 
//     copy cannot change the length, only overwrite elements.
//     the error can be corrected by resizing the vector beforehand or using back_inserter. 

// (b) vec has length zero, reserved capacity does not count towards it. 
//     fill_n cannot change the length, only overwrite elements.
//     the error can be corrected by resizing the vector beforehand or using back_inserter. 
