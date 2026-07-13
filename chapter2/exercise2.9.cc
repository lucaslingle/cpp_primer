/*
Explain the following definitions.
For those that are illegal, explain what's wrong and how to correct it.
(a) std::cin >> int input_value;
(b) int i = {3.14};
(c) double salary = wage = 9999.99;
(d) int i = 3.14;
*/

// (a) 
// invalid. int input_value should be declared (and potentially initialized) 
// before being used, not simultaneously.

// (b) 
// invalid. brace notation requires exact initialization, but type is int.

// (c)
// invalid? variable wage is not declared anywhere. 

// (d)
// valid. the double literal 3.14 will be truncated to 3 and used to initialize i.
