/*
What would happen if `Message` used the synthesized versions
of the copy-control members?
*/

// the synthesized versions would not call `add_to_folders` and `remove_from_folders`,
// so on copy no pointers to the new message would appear in folders,
// and on assign no pointers to the new message would appear in folders,
// and on assign no pointers to the old message would be deleted from folders,
// and on delete no pointers to the old message would be deleted from folders.
