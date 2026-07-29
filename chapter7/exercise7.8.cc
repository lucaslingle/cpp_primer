/*
Why does ```read``` define its ```Sales_data``` parameter as a 
plain reference and print define its parameter as a reference to const?
*/

// because the non-member function read modifies the fields stored in
// the Sales_data struct passed as a reference, it cannot be reference to const.
//
// the non-member function print can define the Sales_data parameter
// as reference to const because it does not intend to modify the Sales_data struct.
