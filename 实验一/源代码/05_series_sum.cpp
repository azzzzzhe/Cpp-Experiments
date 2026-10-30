#include <iostream>
#include <limits>
using namespace std;

int main() {
    int n = 0, a = 0;
    cout << "请输入两个正整数n和a：";
    if (!(cin >> n >> a) || n <= 0 || a <= 0) {
        cout << "输入错误：n和a须为int范围内的正整数。\n";
        return 1;
    }
    long long factor = 10;
    for (int value = a; value >= 10; value /= 10)
        factor *= 10;  // a有几位，就向左移几位。
    long long term = 0, sum = 0;
    const long long maximum = numeric_limits<long long>::max();
    for (int i = 0; i < n; ++i) {
        // 先检查，再运算，避免有符号整数溢出。
        if (term > (maximum - a) / factor) {
            cout << "数值过大：数列项超出long long范围。\n";
            return 1;
        }
        term = term * factor + a;
        if (sum > maximum - term) {
            cout << "数值过大：数列和超出long long范围。\n";
            return 1;
        }
        sum += term;
    }
    cout << "数列和：" << sum << '\n';
    return 0;
}
