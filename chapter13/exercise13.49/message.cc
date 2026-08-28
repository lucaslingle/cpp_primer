/*
Add a move constructor and move-assignment operator to your `Message` class.
*/

// note: i imported utility, because this in this exercise we
// need explicit std::move for the string and set data members, 
// we arent just copying pointers this time.

#include <string>
#include <set>
#include <utility>
using std::string;
using std::set;

class Folder;

class Message {
    friend class Folder;
    public:
        explicit Message(const string &str = ""):
            contents(str) { }
        Message(const Message&);
        Message& operator=(const Message&);
        Message(Message &&) noexcept;
        Message& operator=(Message &&) noexcept;
        ~Message();
        void save(Folder&);
        void remove(Folder&);
    private:
        string contents;
        set<Folder*> folders;
        void addFolder(Folder *);
        void remFolder(Folder *);
        void add_to_folders(const Message&);
        void remove_from_folders();
        void move_folders(Message *);
};

class Folder {
    friend class Message;
    public:
        Folder() = default;
        Folder(const Folder&);
        Folder& operator=(const Folder&);
        ~Folder();
    private:
        set<Message*> messages;
        void addMsg(Message *);
        void remMsg(Message *);
        void add_to_messages(const Folder&);
        void remove_from_messages();
};

void Message::addFolder(Folder *f) {
    folders.insert(f);
}

void Message::remFolder(Folder *f) {
    folders.erase(f);
}

void Message::move_folders(Message *m) {
    folders = std::move(m->folders);
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

void Message::save(Folder &f) {
    addFolder(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    remFolder(&f);
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

Message::Message(Message &&m) noexcept 
    : contents(std::move(m.contents))
{
    move_folders(&m);
    m.contents = string();
}

Message& Message::operator=(Message &&m) noexcept {
    if (this == &m)
        return *this;
    remove_from_folders();

    move_folders(&m);
    contents = std::move(m.contents);
    m.contents = string();
    return *this;
}

void Folder::addMsg(Message *m) {
    messages.insert(m);
}

void Folder::remMsg(Message *m) {
    messages.erase(m);
}

void Folder::add_to_messages(const Folder &f) {
    for (auto m : f.messages)
        m->addFolder(this);
}

void Folder::remove_from_messages() {
    for (auto m : messages)
        m->remFolder(this);
}

Folder::Folder(const Folder &m):
    messages(m.messages) 
{
    add_to_messages(m);
}

Folder::~Folder() {
    remove_from_messages();
}

Folder& Folder::operator=(const Folder &rhs) {
    remove_from_messages();
    messages = rhs.messages;
    add_to_messages(rhs);
    return *this;
}
