#include <iostream>
using namespace std;

bool isNarcissistic(int n) {
    int hundreds = n / 100;
    int tens = n / 10 % 10;
    int units = n % 10;
    return hundreds * hundreds * hundreds + tens * tens * tens
           + units * units * units == n;
}

int main() {
    int number = 0;
    cout << "请输入一个三位正整数：";
    if (!(cin >> number) || number < 100 || number > 999) {
        cout << "输入错误：请输入100~999之间的整数。\n";
        return 1;
    }
    cout << number << (isNarcissistic(number) ?
        " 是水仙花数\n" : " 不是水仙花数\n");
    cout << "所有三位水仙花数：";
    for (int n = 100; n <= 999; ++n) {
        if (isNarcissistic(n)) cout << n << ' ';
    }
    cout << '\n';
    return 0;
}
