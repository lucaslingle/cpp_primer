/*
Test the previous program by giving multiple transactions 
representing multiple ISBNs. The records for each ISBN should be grouped together.
*/

// $ clang++ -std=c++11 -stdlib=libc++ exercise1.23.cc
// $ cat exercise1.24.txt
// 0-201-78345-X 3 20.00
// 0-201-78345-X 2 25.00
// 1-201-78345-X 3 21.00
// 2-201-78345-X 3 20.00
// 2-201-78345-X 2 25.00
// 2-201-78345-X 3 21.00
// $ ./a.out <exercise1.24.txt >exercise1.24.log
// $ cat exercise1.24.log
// 0-201-78345-X has 2 transactions.
// 1-201-78345-X has 1 transactions.
// 2-201-78345-X has 3 transactions.
