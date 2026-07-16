/*
Write a program that reads a set of book sales transactions,
writing each transaction to standard output.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data {
    string bookNo = "";
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main() {
    double price;
    Sales_data item;
    while (cin >> item.bookNo) {
        cin >> item.units_sold;
        cin >> price;
        item.revenue = item.units_sold * price;
        cout << item.bookNo << " " 
             << item.units_sold << " "
             << item.revenue << " "
             << endl;
    }
    return 0;
}
