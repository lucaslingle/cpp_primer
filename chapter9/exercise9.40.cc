/*
If the program in the previous exercise reads 256 words, 
what is the likely capacity after it is resized?
What if it reads 512? 1000? 1048?
*/

// 256: 1024 or more elements are reserved, 
// so after reading 256 the capacity stays constant. 
// resizing by 50% yields a result below the minimum 1024 reserved, 
// so the capacity remains 1024.

// 512: same logic as above, size is below minimum 1024 reserved, 
// so the capacity remains 1024.

// 1000: reading 1000 does not alter capacity of >= 1024.
// resize by 50% gives a required minimum capacity of 1500, 
// so a capacity increase will occur. the new capacity will be >= 1500.

// 1048: reading 1048 may alter the capacity of >= 1024.
// resize by 50% gives a minimum required capacity of 1572,
// so a capacity increase will occur at some point. the new capacity will be >= 1572.
