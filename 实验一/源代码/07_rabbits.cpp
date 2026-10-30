#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int previous = 1, current = 1;
    cout << "月份    兔子对数    兔子只数\n";
    for (int month = 1; month <= 20; ++month) {
        int pairs = 1;
        if (month >= 3) {
            pairs = previous + current;
            previous = current;
            current = pairs;
        }
        cout << setw(4) << month << setw(12) << pairs
             << setw(12) << pairs * 2 << '\n';
    }
    return 0;
}
