/*
In buildMap, what effect if any would there be from rewriting
```
trans_map[key] = value.substr(1);
```
as
```
trans_map.insert({key, value.substr(1)})
```
?
*/

// using the subscript, we obtain an lvalue, so the value associated with 
// the last instance of a key in the transform file is the one used.
//
// when using insert with a map, the insertion fails if the key already exists,
// with the function returning an indicator that the value was not inserted.
// thus, the first occurrence of a key will determine the value used.
