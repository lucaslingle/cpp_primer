/*
Write a program that reads several transactions for the same ISBN.
Write the sum of all transactions that were read.
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
    Sales_data sum, item;

    while (cin >> item.bookNo) {
        cin >> item.units_sold;
        cin >> price;
        item.revenue = item.units_sold * price;

        if (sum.bookNo == "")
            sum.bookNo = item.bookNo;
        if (sum.bookNo != item.bookNo)
            cout << "ISBNs don't match" << endl;

        sum.units_sold += item.units_sold;
        sum.revenue += item.revenue;
    }

    cout << sum.bookNo << " " 
         << sum.units_sold << " "
         << sum.revenue << " "
         << endl;
}
