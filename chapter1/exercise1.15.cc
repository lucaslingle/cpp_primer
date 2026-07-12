/*
Write programs that contain the common errors discussed in the box on page 16. 
Familiarize yourself with the messages the compiler generates. 
*/

#include <iostream>

int main() {
    // error: used colon not semicolon after endl
    //
    // std::cout << "Read each file." << std::endl:
    //
    // got "exercise1.15.cc:5:48: error: expected ';' after expression"

    // error: missing quotes around string literal.
    //
    // std::cout << Update master. << std::endl;
    //
    // got "exercise1.15.cc:10:18: error: use of undeclared identifier 'Update'"

    // error: second output operator is missing.
    //
    // std::cout << "Write new master" std::endl;
    //
    /* got
    exercise1.15.cc:15:36: error: expected ';' after expression
       15 |     std::cout << "Write new master" std::endl;
          |                                    ^
          |                                    ;
    exercise1.15.cc:15:37: error: reference to overloaded function could not be resolved; did you mean to call it?
       15 |     std::cout << "Write new master" std::endl;
          |                                     ^~~~~~~~~
    /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__ostream/basic_ostream.h:542:62: note: possible target for call
      542 | _LIBCPP_HIDE_FROM_ABI inline basic_ostream<_CharT, _Traits>& endl(basic_ostream<_CharT, _Traits>& __os) {
          |                                                              ^
    2 errors generated.
    */

    // error: wrong type.
    //
    // int v0 = "Hello";
    //
    // got "exercise1.15.cc:32:9: error: cannot initialize a variable of type 'int' with an lvalue of type 'const char[6]'"

    int v1 = 0, v2 = 0;

    // error: using nonexistent variable
    //
    // std::cin >> v >> v2;
    //
    // got "exercise1.15.cc:37:17: error: use of undeclared identifier 'v'"

    // error: using namespace item without namespace
    //
    // cout << v1 + v2 << std::endl;
    //
    // got
    /*
    exercise1.15.cc:49:5: error: use of undeclared identifier 'cout'; did you mean 'std::cout'?
       49 |     cout << v1 + v2 << std::endl;
          |     ^~~~
          |     std::cout
    /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/iostream:57:42: note: 'std::cout' declared here
       57 | extern _LIBCPP_EXPORTED_FROM_ABI ostream cout;
          |                                          ^
    */

    // error: missing semicolon on return statement.
    //
    // return 0
    //
    // got "exercise1.15.cc:64:13: error: expected ';' after return statement"
}
