/*
p 213: we cannot pass an object that requires conversion 
to the reference version of ```reset```.
*/

void reset(int &i) {
    i = 0;
}

int main() {
    double d = 3.14;
    reset(d);
    return 0;
}
