/*
What does the following code print?
```
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```
*/

// before the print, the last thing that happens is ri = 10.
// since ri references i, this sets i to 10. 
// the printout is "10 10"

#include <iostream>

int main() {
    int i, &ri = i;
    i = 5; ri = 10;

    std::cout << i << " " << ri << std::endl;
}
