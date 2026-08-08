/*
Write a class that has three unsigned members representing year, month, day.
Write a constructor that takes a string representing a date.
Your constructor should handle a variety of date formats, such as:
January 1, 1900
1/1/1900
Jan 1, 1900
and so on.
*/

// i will assume the month is always first, then day, then year.
#include <iostream>
#include <string>

class Date {
    private:
        unsigned month;
        unsigned day;
        unsigned year;
    public:
        Date(const std::string &s) {
            std::string::size_type pos = 0;

            std::vector<std::string> months = {
                "January", "February", "March",
                "April", "May", "June",
                "July", "August", "September",
                "October", "November", "December"
            };
            unsigned m_int = 1;

            // try to match full month name
            for (const auto &m : months) {
                if ((pos = s.find(m)) != std::string::npos) {
                    this->month = m_int;
                    break;
                }
                ++m_int;
            }

            // try to match month abbreviation
            if (m_int > 12) {
                pos = 0;
                m_int = 1;
                for (const auto &m : months) {
                    if ((pos = s.find(m.substr(0, 3))) != std::string::npos) {
                        this->month = m_int;
                        break;
                    }
                    ++m_int;
                }
            }

            // try to match month as int
            if (m_int > 12) {
                pos = 0;
                m_int = std::stoi(s, &pos, 10);
                this->month = m_int;
            }

            // skip month repr
            std::string s2 = s.substr(pos);
            // skip separators
            std::string s3 = s2.substr(s2.find_first_of("0123456789"));

            this->day = std::stoi(s3, &pos, 10);

            // skip day repr
            std::string s4 = s3.substr(pos);
            // skip separators
            std::string s5 = s4.substr(s4.find_first_of("0123456789"));

            this->year = std::stoi(s5, &pos, 10);
        }
        void print(std::ostream &outp) {
            outp << this->month << "." << this->day << "." << this->year << std::endl;
        }
};

int main() {
    std::vector<std::string> datestrings = {
        "January 1, 1900",
        "1/1/1900",
        "Jan 1, 1900",
    };
    for (const auto &s : datestrings) {
        Date date(s);
        date.print(std::cout);
    }
    return 0;
}