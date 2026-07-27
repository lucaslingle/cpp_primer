/*
Write a function to swap two int pointers.
*/

void pointerswap(int *(&p), int *(&q)) {
    int *temp = p;
    p = q;
    q = temp;
}
