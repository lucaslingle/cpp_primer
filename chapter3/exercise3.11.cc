/*
Is the following range legal? If so, what type is c?
```
const string s = "Keep out!";
for (auto &c : s) { 
    // ...
}
```
*/

// yes it is. 
// c has type const char&.
// each iteration of the forloop creates a reference c to a constant char.
