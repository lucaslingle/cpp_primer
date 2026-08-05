/*
What are the types of the following four objects?
```
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```
*/

// auto only works for multiple declarations when the types are the same.
// it1 would be iterator type, but it2 is const_iterator, so there is a compiler error.
// it3 and it4 are const_iterator type, since they are defined via cbegin.
// 
// the code below doesn't compile, for example:

#include <vector>

int main() {
    std::vector<int> v1;
    const std::vector<int> v2;
    auto it1 = v1.begin(), it2 = v2.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin();
    return 0;
}
