// std::cout << "/*";        
// valid

// std::cout << "*/";        
// valid

// std::cout << /* "*/" */
// invalid: term /* "*/ is comment, term " */ is invalid.

// std::cout << /* "*/" /*  "/*"  */     
// valid: term /* "*/ is comment, term " /*  " is quote, term /*"  */  is comment
