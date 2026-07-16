/*
Write a program that prompts the user for two integers.
Print each number in the range specified by those two integers.
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int v1 = 0, v2 = 0;
    cout << "Enter two numbers in ascending order:" << endl;
    cin >> v1 >> v2;
    while (v1 <= v2) {
        cout << v1 << endl;
        ++v1;
    }
    return 0;
}
