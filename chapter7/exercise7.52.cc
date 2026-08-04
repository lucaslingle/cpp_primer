/*
Using our first version of Sales_data from exercise 2.40, explain the 
following initialization. Identify and fix any problems.
```
Sales_data item = {"0-000-00000-0", 25, 15.99};
```

exercise 2.40 reference code:
```
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```
*/

// It works if the revenue is properly passed since our exercise 2.40 Sales_data  
// was an aggregate class. but 15.99 looks suspiciously like a price, not a revenue.
// It is not divisible by 25, for example. So maybe the init should read:
//
// Sales_data item = {"0-000-00000-0", 25, 25 * 15.99};
