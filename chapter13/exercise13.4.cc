/*
Assuming Point is a class type with a public copy constructor,
identify each use of the copy constructor in this program fragment:
```
Point global;
Point foo_bar(Point arg) {
    Point local = arg, *heap = new Point(global);
    *heap = local;
    Point pa[4] = {local, *heap};
    return *heap;
}
```
*/

// - on binding of the parameter to the argument.
// - when local is assigned from arg.
// - when new Point(global) allocates and constructs a new Point on the heap.
// - when assigning *heap = local.
// - when assigning pa[0] = local.
// - when assigning pa[1] = *heap.
// - when returning *heap.
