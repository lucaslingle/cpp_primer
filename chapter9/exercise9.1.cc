/*
Which is the most appropriate--a vector, deque, or list--for the following
programming tasks? Explain the rationale for your choice. If there is no
reason to prefer one or another container explain why not.

(a) Read a fixed number of words, inserting them into the container 
alphabetically as they are entered. We'll see in the next chapter that 
associative containers are better suited to this problem.

(b) Read an unknown number of words. Always insert new words at the back.
Remove the next value from the front. 

(c) Read an unknown number of integers from a file. Sort the numbers
and then print them to standard output.
*/

// (a) a list is best, because we can insert at any point to maintain
// alphabetical ordering as requested.

// (b) a deque supports fast inserts and deletes at the front and back
// and is most naturally suited to this task. 

// (c) a vector supports random access, making it well-suited for sorting.
// a library array also supports random access, but requires a known size.
