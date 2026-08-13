/*
Write the type of map_it from the loop on p. 430
without using auto or decltype.

reference code:
```
map<string, string::size_type> word_count = {{"Hello", 2}, {"World", 1}};
auto map_it = word_count.cbegin();
```
*/

map<string, string::size_type>::const_iterator;