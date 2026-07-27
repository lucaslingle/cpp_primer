/*
Write a function that takes an int and a pointer to an int
and returns the larger of the int value or the value to which the pointer points.
What type should you use for the pointer?
*/

int func(int n, const int *p) {
    return (n > *p) ? n : *p;
}
