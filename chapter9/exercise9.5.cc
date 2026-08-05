/*
Rewrite the previous program to return an interator to the requested element.
Note that the program must handle the case where the element is not found.
*/

// if not found, we'll return the end iterator.
// the end iterator is one after the inspection range, 
// so it is never tested for the query element, 
// thus making it a meaningful indicator the element isn't in the range.
//
// for the return type, we will use const_iterator 
// since if there is an implicit type conversion to const during the function call, 
// we can always cast away the const after, with a fully-valid const_cast.

std::vector<int>::const_iterator search(
    std::vector<int>::const_iterator begin, 
    std::vector<int>::const_iterator end, 
    int query
) {
    while (begin != end) {
        if (*begin == query)
            return begin;
        ++begin;
    }
    return end;
}
