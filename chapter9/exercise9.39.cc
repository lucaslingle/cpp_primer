/*
Explain what the following program fragment does:
```
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
    svec.push_back(word);
svec.resize(svec.size() + svec.size()/2);
```
*/

// it initially reserves at least 1024 elements for the vector of strings svec.
// then it reads all words from standard input into svec.
//
// depending on the number of words, svec.capacity() may be greater than the
// number of initially-reserved elements from the call to svec.reserve(1024).
//
// finally, it resizes the vector by adding 50% more elements than the current
// size of svec, each of which is value-initialized. 
// this may further alter the result of svec.capacity(). 
