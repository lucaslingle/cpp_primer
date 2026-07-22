/*
Our program that distinguished between high pass, pass, and fail dependend 
on the fect that the conditional operator is right associative. 
Describe how that operator would be evaluated if the operator were left associative. 
*/

// char *categorize_v1(int grade) {
//     return (grade > 90) ? "high pass"
//          : (grade > 75) ? "pass"
//          : (grade <= 75 && grade >= 60) ? "low pass"
//          : "fail";
// }

// if it were left associative, the grouping have an innermost
// (grade > 90) ? "high pass" : (grade > 75)
// as a condition for another conditional
//             ? "pass" : (grade <= 75 && grade >= 60)
// as a condition for another conditional
//             ? "low pass" : "fail";
