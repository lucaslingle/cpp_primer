/*
Show an example of each of the six ways to create and initialize a vector.
Explain what values each vector contains.
*/

#include <vector>
#include <string>
using std::vector;
using std::string;

int main() {
    // default initialization
    vector<string> v1; // empty

    // copy initialization
    vector<string> assignee = {"hello"};
    vector<string> v2(assignee);  // {"hello"}

    // fill with specific value
    vector<string> v3(2, "hello");  // {"hello", "hello"}

    // value initialization
    vector<string> v4(2);           // {"", ""}

    // list initialization
    vector<string> v5{"hello", "world"};  // {"hello", "world"}

    // iterator initialization
    vector<string> ctx = {"hello", "world", "the", "quick", "brown", "fox"};
    vector<string> v6(ctx.cbegin(), ctx.cend());

    return 0;
}
