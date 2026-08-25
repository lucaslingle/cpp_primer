/*
We did not use copy and swap to define the Message assignment operator.
Why do you suppose this is so?
*/

// The swap function defined is

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

// copying would require calling the copy constructor, adding a new pointer to
// every folder containing the passed message.
// this work would be immediately undone by swap's remMsg on rhs.folders.
//
// swap also adds the lhs message (now on rhs) to rhs.folders,
// but this is followed by Message::~Message() when the assignment operator scope ends.
// this destructor would call remove_from_folders, undoing the work at the end of swap. 
