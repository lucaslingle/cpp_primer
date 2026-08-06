/*
Using the following definition of ia, copy ia into a vector
and into a list. Use the single-iterator form of erase to remove 
the elements with odd values from your list and even values from your vector. 
```
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
```
*/

#include <iostream>
#include <vector>
#include <list>

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> vec;
    std::list<int> lst;
    for (const auto &i : ia) {
        vec.push_back(i);
        lst.push_back(i);
    }

    auto iter = vec.cbegin();
    while (iter != vec.cend()) {
        if (*iter % 2 == 0)
            iter = vec.erase(iter);
        else
            ++iter;
    }

    auto iter2 = lst.cbegin();
    while (iter2 != lst.cend()) {
        if (*iter2 % 2 == 1)
            iter2 = lst.erase(iter2);
        else
            ++iter2;
    }

    std::cout << "vec: ";
    for (const auto &i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "lst: ";
    for (const auto &i : lst)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
