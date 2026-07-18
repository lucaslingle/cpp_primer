/*
Write a program the define an array of ten ints. 
Give each element the same value as its position in the array.
*/

int main() {
    int arr[10];
    for (size_t i = 0; i != 10; ++i)
        arr[i] = i;
    return 0;
}
