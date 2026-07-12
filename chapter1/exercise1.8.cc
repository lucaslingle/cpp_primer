// Indicate which, if any, of the following output statements are legal:
// ```
// std::cout << "/*";
// std::cout << "*/";
// std::cout << /* "*/" */
// std::cout << /* "*/" /*  "/*"  */   
// ```
// After you've predicted what will happen, 
// test your answers by compiling a program with each of these statements.
// Correct any errors you encounter.

#include <iostream>

// valid
// int main() {
//     std::cout << "/*";
//     return 0;
// }

// valid
// int main() {
//     std::cout << "*/";
//     return 0;
// }

// invalid: term /* "*/ is comment, term " */ is invalid.
// int main() {
//     std::cout << /* "*/" */;
//     return 0;
// }

// valid: term /* "*/ is comment, term " /*  " is quote, term /*"  */  is comment
// int main() {
//     std::cout << /* "*/" /*  "/*"  */;
//     return 0;
// }
