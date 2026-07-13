/*
To calculate a mortgage payment, what types would you use for the 
rate, principal, and payment? Explain why you selected each choice.
*/

// Rate.
// In practice, a double is usually about as fast as a float, so there is little reason to use float.
// A separate reason I would use double for the rate, is because it is being multiplied 
// by a large number (the principal) to obtain the interest portion of the payment.
// I am not using long double because the standard only guarantees 10 significant digits, 
// same as a double. A long double is mainly used as a way to accommodate special-purpose hardware. 

// Principal.
// I would use an unsigned long. The standard only guarantees 16 bits for an int,
// while a long guarantees 32 bits. The max for a 16-bit unsigned integer would be 65,536, 
// instead of just over 4 billion for a 32-bit unsigned integer. 
// The former is insufficient to represent a principal for a USD-denominated mortgage, 
// while the latter is sufficient. 
// It is not necessary to use a long long, because there are no houses above 4 billion dollars. 

// Payment.
// Although it may typically suffice to use an integer for the payment, 
// we want to cover exceptional cases. The most expensive house in LA is $400M.
// If some obtained a 20 year mortgage, the payment of the principal per month would have to be 
// $400M / (20 * 12) = $1.67M, which far exceeds the guaranteed capacity of an unsigned int at only 16 bits. 
// Therefore I would use a long. 
