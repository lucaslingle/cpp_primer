/*
Write a function that takes a pair of iterators to a vector<int>
and an int value. Look for that value in the range and return a bool
indicating whether it was found.
*/

bool search(
    std::vector<int>::const_iterator begin, 
    std::vector<int>::const_iterator end, 
    int query
) {
    while (begin != end) {
        if (*begin == query)
            return true;
        ++begin;
    }
    return false;
}
