/*
In our ```check``` function we didn't check whether ```i``` was greater than zero. 
Why is it okay to omit that check?
*/

// since size_type is unsigned, for values of i < 0, they are implicitly converted
// to very large integral values, which will fail the range check.
// 
// as for allowing i == 0 as an input, it allows us to continue to use ```check``` 
// as a helper function to throw an out_of_range error in the scenario 
// where the data size is zero. 