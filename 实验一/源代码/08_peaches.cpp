#include <iostream>
using namespace std;

int main() {
    int peaches = 1;  // 第10天早上、尚未进食时剩余1个。
    for (int day = 9; day >= 1; --day)
        peaches = (peaches + 1) * 2;
    cout << "第一天共摘了 " << peaches << " 个桃子\n";
    return 0;
}
