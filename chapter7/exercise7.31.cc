/*
Define a pair of classes X and Y, in which X has a pointer to Y, 
and Y has an object of type X.
*/

class Y;

class X {
    Y *item;
}

class Y {
    X item;
}
