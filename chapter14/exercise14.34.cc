/*
Define a function-object class to perform an if-then-else operation:
the call operator for this test should take three parameters. It should test
its first parameter and if that test succeeds, it should return its second parameter;
otherwise it should return its third parameter.
*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class TernaryOperator {
    public:
        string operator()(bool cond, string yes, string no) const {
            return (cond) ? yes : no;
        }
};

int main() {
    TernaryOperator tern;
    cout << tern(1 > 0, "1 > 0", "1 <= 0");
    cout << endl;
    return 0;
}
