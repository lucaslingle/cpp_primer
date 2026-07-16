/*
Compile the following program to see what happens when you
forget the semicolon after a class definition. Remember the message for
future reference.
*/

struct Foo {} // no semicolon
int main() {
    return 0;
}

// err msg
// exercise2.39.cc:7:14: error: expected ';' after struct