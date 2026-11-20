#pragma once

#include <iostream>

class X;

class Y {
public:
    void g(X* x);
};

class Z {
public:
    void f(X* x);
};

void h(X* x);

class X {
public:
    explicit X(int initial = 0) : i(initial) {}

    void PrintX() const {
        std::cout << "i = " << i << '\n';
    }

private:
    int i;
    friend void Y::g(X* x);
    friend class Z;
    friend void h(X* x);
};

inline void Y::g(X* x) {
    ++x->i;
}

inline void Z::f(X* x) {
    x->i += 5;
}

inline void h(X* x) {
    x->i += 10;
}

