#include<iostream>
using namespace std;

class SimpleCircle {
private:
	int* itsRadius = nullptr;
public:
	void setRadius(int r) {
		itsRadius = new int(0);
		*itsRadius = r;
		cout << "Success.\n";
	}
	void showRadius() {
		if (itsRadius == nullptr) {
			cout << "Error.\n";
			return;
		}
		cout << "Radius is " << *itsRadius << endl;
	};
	void deleteRadius() {
		delete itsRadius;
		cout << "Success.";
	}
};