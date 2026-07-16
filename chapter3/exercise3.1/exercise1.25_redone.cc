/*
Compile and execute the bookstore program.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

struct Sales_data {
    string bookNo = "";
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main() {
    double price;
    Sales_data total;
    if (cin >> total.bookNo) {
        cin >> total.units_sold;
        cin >> price;
        total.revenue = total.units_sold * price;

        Sales_data trans;
        while (cin >> trans.bookNo) {
            cin >> trans.units_sold;
            cin >> price;
            trans.revenue = trans.units_sold * price;

            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                cout << total.bookNo << " " 
                     << total.units_sold << " "
                     << total.revenue << " "
                     << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " 
             << total.units_sold << " "
             << total.revenue << " "
             << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
