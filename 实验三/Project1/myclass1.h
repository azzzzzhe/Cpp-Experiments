#pragma once

class Cat {
public:
    Cat() {
        ++numOfCats;
    }

    Cat(const Cat&) : Cat() {}
    Cat& operator=(const Cat&) = default;

    ~Cat() {
        --numOfCats;
    }

    static int getNumOfCats() {
        return numOfCats;
    }

private:
    static int numOfCats;
};

