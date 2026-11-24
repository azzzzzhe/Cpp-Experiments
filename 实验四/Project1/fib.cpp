#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


long fib(int n) {
	if (n <= 0) {
		cout << "out of range";
	}
	if (n == 1 || n == 2)return 1;
	return fib(n - 1) + fib(n - 2);
}

int main() {
	cout << fib(20)<<endl;
	cout << fib(30)<<endl;
	cout << fib(40)<<endl;

	return 0;
}