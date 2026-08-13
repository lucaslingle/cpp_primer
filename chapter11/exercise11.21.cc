/*
Assuming word_count is a map from string to size_t and word is a string,
explain the following loop:
```
while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
```
*/

// inserts the pair {word, 0} into the map word_count, 
// fetches the first element of the pair returned by insert, which is an iterator,
// and dereferences the iterator to extract the second element from the pair it points to,
// and increments that element, which is a value of type size_t.
