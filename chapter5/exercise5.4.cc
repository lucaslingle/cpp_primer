/*
Explain each of the following examples, and correct any problems you detect.
(a) while (string::iterator iter != s.end()) { ... }
(b) while (bool status = find(word)) { ... }
    if (!status) { ... }
*/

// (a) iter is defined inside the while condition, yet is not initialized.
// (b) status is defined within the while condition, yet is used after the loop ends.
