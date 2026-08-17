/*
Explain whether the following call to the ```process``` function
defined on p. 464 is correct. If not, how would you correct the call?
```
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```
*/

// the line ```process(shared_ptr<int>(p))``` copy-initializes a temporary shared ptr,
// from another shared ptr. the reference count inside process is 2.
// note that the syntax can be simplified to process(p), as in the main text.
