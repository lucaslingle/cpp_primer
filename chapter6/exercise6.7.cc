/*
Write a function that returns zero when it is first called, 
then generates numbers in sequence each time it is called again.
*/

int counter() {
    static int n = 0;
    return n++;
}
