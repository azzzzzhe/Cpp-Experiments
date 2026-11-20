#include <iostream>
#include "myclass1.h"

int Cat::numOfCats = 0;

void testCats() {
    std::cout << "[5-7] Cat object count\n";
    std::cout << "Before construction: " << Cat::getNumOfCats() << '\n';
    {
        Cat first, second;
        std::cout << "Two outer objects: " << Cat::getNumOfCats() << '\n';
        {
            Cat inner;
            Cat copy = first;
            std::cout << "With inner object and copy: "
                      << Cat::getNumOfCats() << '\n';
        }
        std::cout << "After inner scope: " << Cat::getNumOfCats() << '\n';
    }
    std::cout << "After outer scope: " << Cat::getNumOfCats() << '\n';
}
