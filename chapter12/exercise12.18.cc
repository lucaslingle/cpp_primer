/*
Why doesn't shared_ptr have a ```release``` member?
*/

// if more than one shared_ptr exists pointing to the same object, 
// they would all have to relinquish control when release was called.
// if they did not, there would be double-free bugs. 
