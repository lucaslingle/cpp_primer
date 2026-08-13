/*
What would happen if we used the subscript operator 
instead of ```find``` in the ```transform``` function?
*/

// if used in our transform function, 
// the subscript operator will create an entry every time a lookup occurs.
//
// if we use the return value of m[s] for any non-occurring word,
// it will be the value initialized string, which is empty.
