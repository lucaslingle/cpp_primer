/*
Is the following program legal? If so, what values are printed?
```
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```
*/

// yes it is a valid program.
// the for-loop uses a local object also called i
//     which is only valid for the duration of the loop.
// afterwards, the global i is the only one in-scope.
// the printout reads "100 45", because (0 + 1 + ... + 9) = 9*10/2 = 45.
