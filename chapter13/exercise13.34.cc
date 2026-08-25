/*
Write the `Message` class as described in this section.
*/

#include <string>
#include <set>
using std::string;

class Folder;

class Message {
    friend class Folder;
    public:
        explicit Message(const string &str = ""):
            contents(str) { }
        Message(const Message&);
        Message& operator=(const Message&);
        ~Message();
        void save(Folder&);
        void remove(Folder&);
    private:
        string contents;
        set<Folder*> folders;
        void add_to_folders(const Message&);
        void remove_from_folders();
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_folders(const Message &m) {
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_folders() {
    for (auto f : folders)
        f->remMsg(this);
}

Message::Message(const Message &m):
    contents(m.contents), folders(m.folders) 
{
    add_to_folders(m);
}

Message::~Message() {
    remove_from_folders();
}

Message& Message::operator=(const Message &rhs) {
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}
