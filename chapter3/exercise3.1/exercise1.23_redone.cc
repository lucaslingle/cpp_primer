/*
Write a program that reads several transactions and counts 
how many transactions occur for each ISBN. 
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data {
    string bookNo = "";
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// assumption: the inputs are sorted by isbn already, as with exercises 1.17-1.18.
// assumption: want number of txs not number of copies, as units_sold is private var.
int main() {
    double price;
    Sales_data isum, ival;
    if (cin >> isum.bookNo) {
        cin >> isum.units_sold;
        cin >> price;
        isum.revenue = isum.units_sold * price;

        int cnt = 1;
        while (cin >> ival.bookNo) {
            cin >> ival.units_sold;
            cin >> price;
            ival.revenue = ival.units_sold * price;

            if (isum.bookNo == ival.bookNo) {
                ++cnt;
            } else {
                cout << isum.bookNo << " has "
                     << cnt << " transactions." << endl;
                isum = ival;
                cnt = 1;
            }
        }
        cout << isum.bookNo << " has "
             << cnt << " transactions." << endl;
    }
    return 0;
}
