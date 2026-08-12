/*
Use find to find the last element in a list of ints with value 0.
*/

#include <list>
#include <algorithm>

int main() {
    std::list<int> ls = {0, 1, 2, 3, 0, 9, 8, 7, 0, 4, 5, 6};
    auto it = std::find(ls.crbegin(), ls.crend(), 0);
    return 0;
}
