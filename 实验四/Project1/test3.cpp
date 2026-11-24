#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void reverse(string& s) {
    if (s.length() <= 1)
        return;

    char t = s.front();
    s[0] = s[s.length() - 1];
    s[s.length() - 1] = t;

    if (s.length() >= 3) {
        string sub = s.substr(1, s.length() - 2);
        reverse(sub);

        // 将反转后的子串放回原字符串
        s.replace(1, s.length() - 2, sub);
    }
	
}

int main() {
	string s;
	getline(cin, s);//读一整行字符串
	reverse(s);
	cout << s.substr(1, s.length() - 2);
	cout <<"reverse: " << s;

	return 0;
}