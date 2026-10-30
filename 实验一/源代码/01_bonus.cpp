#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double profit = 0, bonus = 0;
    cout << "请输入当月利润（元）：";
    if (!(cin >> profit) || !isfinite(profit) || profit < 0) {
        cout << "输入错误：利润必须为非负数。\n";
        return 1;
    }
    if (profit <= 100000)
        bonus = profit * 0.10;
    else if (profit <= 200000)
        bonus = 10000 + (profit - 100000) * 0.075;
    else if (profit <= 400000)
        bonus = 17500 + (profit - 200000) * 0.05;
    else if (profit <= 600000)
        bonus = 27500 + (profit - 400000) * 0.03;
    else if (profit <= 1000000)
        bonus = 33500 + (profit - 600000) * 0.015;
    else
        bonus = 39500 + (profit - 1000000) * 0.01;
    cout << fixed << setprecision(2);
    cout << "应发奖金：" << bonus << " 元\n";
    return 0;
}
