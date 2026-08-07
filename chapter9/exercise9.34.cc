/*
Assuming vi is a container of ints that includes even and odd values,
predict the behavior of the following loop. After you've analyzed this loop,
write a program to test whether your expectations were correct.
```
iter = vi.begin();
while (iter != vi.end())
    if (*iter % 2)
        iter = vi.insert(iter, *iter);
    ++iter;
```
*/

// well for one thing the ++iter isn't inside the while loop.
//
// so what happens is we check iter != vi.end(), 
// and if iter dereferences to an odd element, 
// we insert the same odd element before that one.
//
// we then point to the inserted element, 
// which is *before* the one we were pointing to.
//
// this process loops infinitely, left-inserting odd elements of the same value
// after the first odd element is identified.
//
// program below hangs, which suggests i was right.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vi = {0, 1, 2, 3, 4};

    auto iter = vi.begin();
    while (iter != vi.end())
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        ++iter;

    return 0;
}
