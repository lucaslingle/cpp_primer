/*
Write a program that reads two Sales_item objects that have the same ISBN
and produces their sum.
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
    Sales_data item, item2, item3;

    cin >> item.bookNo;
    cin >> item.units_sold;
    cin >> price;
    item.revenue = item.units_sold * price;

    cin >> item2.bookNo;
    cin >> item2.units_sold;
    cin >> price;
    item2.revenue = item2.units_sold * price;

    item3.bookNo = item.bookNo;
    item3.units_sold = item.units_sold + item2.units_sold;
    item3.revenue = item.revenue + item2.revenue;

    cout << item3.bookNo << " " 
         << item3.units_sold << " "
         << item3.revenue << " "
         << endl;

    return 0;
}
