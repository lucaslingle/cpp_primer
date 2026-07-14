/*
Which of the following are illegal? 
For those that are illegal explain why.

(a) const int buf;
(b) int cnt = 0;
(c) const int sz = cnt;
(d) ++cnt; ++sz;
*/

// (a) is invalid because it is an uninitialized constant.
// (b) is valid
// (c) is valid, it copies the int stored in cnt into sz.
// (d) is invalid. incrementing cnt is fine, but sz is constant so cannot be changed.
