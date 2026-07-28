/*
Revise the ```arrPtr``` function on p. 230 to use a reference to the array.
*/

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) *arrPtr(int i) {
    return (i % 2) ? &odd : &even;
}

decltype(odd) &arrRef(int i) {
    return (i % 2) ? odd : even;
}
