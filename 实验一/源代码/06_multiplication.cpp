#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "九九乘法口诀表\n";
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= i; ++j)
            cout << j << '*' << i << '=' << setw(2) << j * i << "  ";
        cout << '\n';
    }
    return 0;
}
