/*
In the program on p. 349 that erased a range of elements, 
what happens if elem1 and elem2 are equal? 
What if elem2 or both elem1 and elem2 are the off-the-end iterator?

reference code:
```
elem1 = slist.erase(elem1, elem2);
```
*/

// if they are equal, the range should count as empty and nothing should be erased.
// if elem2 is the off-the-end iterator, the entire list<string> from 
// elem1 onward will be deleted. 
// if elem2 is the off-the-end iterator, no elements will be deleted. 
// i verify this all below.

#include <iostream>
#include <string>
#include <list>

void print_slist(const std::list<std::string> &slist) {
    for (auto const &item : slist)
        std::cout << item << " ";
    std::cout << std::endl;
}

int main() {
    std::list<std::string> slist = {"a", "b", "c", "d", "e"};

    std::cout << "initial:" << std::endl;
    print_slist(slist);

    auto iter = slist.cbegin();
    iter++;
    iter++;
    slist.erase(iter, iter);
    std::cout << "empty range erasure test:" << std::endl;
    print_slist(slist);

    iter = slist.cend();
    slist.erase(iter, iter);
    std::cout << "both ending erasure test:" << std::endl;
    print_slist(slist);

    iter = slist.cbegin();
    iter++;
    iter++;
    slist.erase(iter, slist.cend());
    std::cout << "far ending erasure test:" << std::endl;
    print_slist(slist);

    return 0;
}