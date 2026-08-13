/*
Explain the meaning of the operand ```pos.first->second``` 
used in the output expression of the final program in this section.

reference code:
```
for (auto pos = authors.equal_range(search_item);
     pos.first != pos.second; ++pos.first)
    cout << pos.first->second << endl;
```
*/

// authors.equal_range(search_item) returns a pair of iterators
// indicating an iterator range where the key ```search_item``` is present.
// pos.first->second gets the first iterator and dereferences it (->),
// to obtain the second field in the (key, value) pair object for the current entry.
//
// in other words, it yields the value of the key-value pair pointed to by the first iterator,
// which is repeatedly incremented in the for-loop header.