/*
Revise your program from the previous exercise to use a try block
to catch the exception. The catch clause should print a message to the user
and ask them to supply a new number and repeat the code inside the try.
*/

#include <iostream>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;

int main() {
    int v1, v2;
    while (cin >> v1 >> v2) {
        try {
            if (v2 == 0)
                throw runtime_error("cannot divide by zero!");
            cout << v1 / v2 << endl;
            return 0;
        } catch (runtime_error err) {
            cout << err.what() << "\nTry again [y/n]?" << endl;
            string tryagain;
            cin >> tryagain;
            if (!cin || tryagain == "n")
                return -1;
        }
    }
}
