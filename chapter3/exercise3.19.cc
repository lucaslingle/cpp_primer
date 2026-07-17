/*
List three ways to define a vector and give it ten elements, each with
the value 42. Indicate whether there is a preferred way to do so and why.
*/

// method 1
// copy initialization.
// vector<int> vec = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42}

// method 2
// initializing from element count and value.
// vector<int> vec(10, 42);

// method 3
// adding elements with push_back.
// vector<int> vec; 
// for (int i = 0; i < 10; i++)
//     vec.push_back(42);

// since all the elements of the array are the same,
// method 1 or 2 is most efficient. 
// if the elements differed (and were only known at runtime), 
// method 3 would be most efficient. 