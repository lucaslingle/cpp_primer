/*
Although the following are legal, they probably do not behave 
as the programmer expects. Why? Rewrite the expressions as you think they should be.

(a) if (p = getPtr() != 0)
(b) if (i = 1024)
*/

// (a) equality/inequality has higher precedence than assignment,
// so the condition is essentially (p = (getPtr() != 0)), 
// which checks if getPtr() returns non-nullptr and returns a boolean based on that.
// this boolean is attempted to be assigned to the pointer p. 
// the likely intended way is ```if ((p = getPtr()) != 0)```.

// (b) ```if (i = 1024)``` always sets i to 1024 and evaluates 
// the resulting value of i converted to a boolean. it is always true, 
// so there is no reason for an if statement. 
// the user likely meant to write ```if (i == 1024)```.
