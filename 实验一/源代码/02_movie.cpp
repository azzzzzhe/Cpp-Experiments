#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double score = 0;
    cout << "请输入电影评分（0~10的整数）：";
    if (!(cin >> score) || !isfinite(score) || score < 0 ||
        score > 10 || floor(score) != score) {
        cout << "输入错误：评分必须是0~10的整数。\n";
        return 1;
    }
    if (score >= 9)
        cout << "你认为电影经典\n";
    else if (score >= 7)
        cout << "你认为电影非常好\n";
    else if (score >= 5)
        cout << "你认为电影一般\n";
    else
        cout << "你认为电影烂片\n";
    return 0;
}
