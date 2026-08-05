/*
What is wrong with the following program? How might you correct it?
```
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) {
   ...
}
```
*/

// while vector and string iterators support relational operators,
// not all containers' iterators do; in particular, lists do not. 
// the fix is to use iter1 != iter2 as the loop condition.
