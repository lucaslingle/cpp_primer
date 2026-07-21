/*
Explain the behavior of the condition in the following if:
```
const char *cp = "Hello World";
if (cp && *cp)
```
*/

// the left hand operand is converted to boolean true, 
// since the char pointer is non-null.
// the right hand operand is converted to boolean true, 
// since the first character of the C-style string is not a null byte. 
// thus the condition evaluates as true.