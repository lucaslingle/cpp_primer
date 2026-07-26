int fact(int n) {
    int result = 1;
    while (n >= 1)
        result *= n--;
    return result;
}
