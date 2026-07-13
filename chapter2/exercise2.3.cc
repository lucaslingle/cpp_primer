/*
What output will the following code produce?

```
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;

int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;

std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```
*/

// std::cout << u2 - u << std::endl;
// it's 32.

// std::cout << u - u2 << std::endl;
// we obtain -32 but it's an unsigned int, 
// where -1 corresponds to 4,294,967,295
// and this is 31 less than that, so it
// comes out to 4,294,967,264.

// std::cout << i2 - i << std::endl;
// it's 32.

// std::cout << i - i2 << std::endl;
// it's -32.

// std::cout << i - u << std::endl;
// both are converted to unsigned, so it's 10 - 10, zero.

// std::cout << u - i << std::endl;
// both are converted to unsigned, so it's 10 - 10, zero.