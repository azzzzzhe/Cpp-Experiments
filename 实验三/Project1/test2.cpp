#include <iostream>
#include "myclass2.h"

void testCats();

int main() {
    testCats();

    std::cout << "\n[5-13] Friend access\n";
    X obj(0);
    Y y;
    Z z;

    std::cout << "Initial: ";
    obj.PrintX();

    y.g(&obj);
    std::cout << "After Y::g (+1): ";
    obj.PrintX();

    z.f(&obj);
    std::cout << "After Z::f (+5): ";
    obj.PrintX();

    h(&obj);
    std::cout << "After h (+10): ";
    obj.PrintX();

    return 0;
}
