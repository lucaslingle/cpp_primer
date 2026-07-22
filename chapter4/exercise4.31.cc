/*
The program in this section used the prefix increment and decrement operators.
Explain why we used prefix and not postfix. 
What changes would have to be made to use the postfix versions?
Rewrite the program to use postfix versions.
*/

// explain: no real reason except prefix is slightly faster.
// what changes: move the prefix to postfix in the comma expression.
// rewrite:

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> ivec(10);
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;

    vector<int> ivec2(10);
    vector<int>::size_type cnt2 = ivec2.size();
    for (vector<int>::size_type ix2 = 0; ix2 != ivec2.size(); ix2++, cnt2--)
        ivec2[ix2] = cnt2;
    for (auto i2 : ivec2)
        cout << i2 << " ";
    cout << endl;

    return 0;
}
