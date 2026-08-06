/*
Write a function that takes a forward_list<string> 
and two additional string arguments. The function should find the first string
and insert the second immediately following the first. If the first string is
not found, then insert the second string at the end of the list.
*/

#include <iostream>
#include <forward_list>

void fix_and_insert(
    std::forward_list<std::string> &flst,
    std::string anchor,
    std::string word
) {
    auto curr = flst.begin();
    while (curr != flst.end() && *curr != anchor)
        ++curr;
    flst.insert_after(curr, word);
}

int main() {
    std::forward_list<std::string> flst = {"hello", "world", "how", "are", "you"};
    char anchor[] = "world";
    char word[] = "hi";
    
    fix_and_insert(flst, anchor, word);

    for (const auto &item : flst)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
