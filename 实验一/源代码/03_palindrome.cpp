#include <iostream>
using namespace std;

int main() {
    long long number = 0;
    cout << "请输入一个整数：";
    if (!(cin >> number)) {
        cout << "输入错误：请输入long long范围内的整数。\n";
        return 1;
    }
    bool palindrome = false;
    if (number >= 0 && (number == 0 || number % 10 != 0)) {
        long long left = number, right = 0;
        // 只反转后半部分，避免反转整个整数时溢出。
        while (left > right) {
            right = right * 10 + left % 10;
            left /= 10;
        }
        palindrome = (left == right || left == right / 10);
    }
    cout << number << (palindrome ? " 是回文数\n" : " 不是回文数\n");
    return 0;
}
