/*
The program on p. 354 to remove even-valued elements and duplicate odd ones
will not work on a list or a forward_list. Why? Revise the program so that
it works on these types as well.

reference code:
```
vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
auto iter = vi.begin();
while (iter != vi.end()) {
    if (*iter % 2) {
        iter = vi.insert(iter, *iter);
        iter += 2;
    } else
        iter = vi.erase(iter);
}
```
*/

// for list, the reason it doesn't work is that list doesn't support indexing, 
// and thus doesn't have an iterator that supports arithmetic operations.
// it has to be advanced one at a time.
//
// for forward_list, we have to use insert_after and erase_after.

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

void vector_sillyloop(std::vector<int> &vec) {
    auto iter = vec.begin();
    while (iter != vec.end()) {
        if (*iter % 2) {
            iter = vec.insert(iter, *iter);
            iter += 2; // skip over inserted element and element it was inserted before
        } else
            iter = vec.erase(iter);
    }
} 

void list_sillyloop(std::list<int> &lst) {
    auto iter = lst.begin();
    while (iter != lst.end()) {
        if (*iter % 2) {
            iter = lst.insert(iter, *iter);
            ++iter; // skip over inserted element and element it was inserted before
            ++iter;
        } else
            iter = lst.erase(iter);
    }
}

void forward_list_sillyloop(std::forward_list<int> &flst) {
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) {
            prev = flst.insert_after(prev, *curr);
            ++prev;
            ++curr;
        } else
            curr = flst.erase_after(prev);
    }
}

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4};
    std::list<int> lst = {0, 1, 2, 3, 4};
    std::forward_list<int> flst = {0, 1, 2, 3, 4};

    vector_sillyloop(vec);
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    list_sillyloop(lst);
    for (auto i : lst)
        std::cout << i << " ";
    std::cout << std::endl;

    forward_list_sillyloop(flst);
    for (auto i : flst)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
