/*
What would happen if we called ```process``` as follows?
```
process(shared_ptr<int>(p.get()));
```
*/

// the line ```process(shared_ptr<int>(p.get()))``` 
// initializes plain ptr underlying a shared_ptr.
//
// the reference count inside process is 1, 
// and when process returns the temporary shared_ptr will go out of scope.
// the underlying dynamic memory will be freed, and p will be a dangling pointer.
//
// in addition, since p is a shared_ptr, it may eventually delete the dynamic memory
// a second time if its stored reference count reaches zero before the program ends. 
