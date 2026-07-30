/*
Update your person class to hide its implementation.
*/

struct Person {
    friend std::istream &read(std::istream &ist, Person &person);
    friend std::ostream &print(std::ostream &ost, const Person &person);
    private:
        // data members should be private to prevent unauthorized changes 
        // by class users
        std::string name;
        std::string address;
    public:
        // constructors and data member getters should be public to allow
        // class instantiation and data inspection. 
        Person() = default;
        Person(const std::string &n): name(n) { }
        Person(const std::string &n, const str::string &a): name(n), address(a) { }
        std::string get_name() const {
            return name;
        }
        std::string get_address() const {
            return address;
        }
}

std::istream &read(std::istream &ist, Person &person) {
    ist >> person.name >> person.address;
    return ist;
}

std::ostream &print(std::ostream &ost, const Person &person) {
    ost << person.name << " @ " << person.address;
    return ost;
}
