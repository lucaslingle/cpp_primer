/*
Write a program that uses a while to sum the numbers from 50 to 100.
*/

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int sum = 0, val = 50;
    while (val <= 100) {
        sum += val;
        ++val;
    }
    cout << "The sum of 50 to 100 is "
              << sum << endl;
    return 0;
}
