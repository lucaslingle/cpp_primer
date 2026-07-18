/*
In this section we noted that it was not only illegal but meaningless to
try to add two pointers. Why would adding two pointers be meaningless?
*/

// it would be meaningless because it would offset one pointer 
// by the amount equal to the stored memory address of another pointer. 
// since this memory address can change, the behavior is undefined.
