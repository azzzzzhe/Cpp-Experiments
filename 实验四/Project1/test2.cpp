#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

bool isletter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
	string s;
	getline(cin, s);//¶ÁÒ»ÕûÐÐ×Ö·û´®
	
	int count = 0;
	for (char c : s) {
		if(isletter(c))count++;
	}
	cout << count<<" letter(s)";

	return 0;
}