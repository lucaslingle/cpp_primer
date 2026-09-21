/*
What happens in the following calls:
```
template <typename T> f1(T, T);
template <typename T1, typename T2> f2(T1, T2);
int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;
(a) f1(p1, p2);
(b) f2(p1, p2);
(c) f1(cp1, cp2);
(d) f2(cp1, cp2);
(e) f1(p1, cp1);
(f) f2(p1, cp1);
```
*/

// (a) T is deduced as int *
// (b) T1 is deduced as int *, T2 is deduced as int *
// (c) T is deduced as const int *
// (d) T1 is deduced as const int *, T2 is deduced as const int *
// (e) T cannot be deduced
// (f) T1 is deduced as int *, T2 is deduced as const int *.