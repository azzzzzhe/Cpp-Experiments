#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

short int divide(unsigned short int x, unsigned short int y) {
    if (y == 0) return -1;
    int quotient = x / y;
    if (quotient > numeric_limits<short int>::max())
        throw overflow_error("Quotient is outside the short int range.");
    return static_cast<short int>(quotient);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    int limit = static_cast<int>(sqrt(n));
    for (int i = 2; i <= limit; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

long long gcd(int x, int y) {
    long long a = abs(static_cast<long long>(x));
    long long b = abs(static_cast<long long>(y));
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

long long lcm(int x, int y) {
    if (x == 0 || y == 0) return 0;
    long long a = abs(static_cast<long long>(x));
    long long b = abs(static_cast<long long>(y));
    return (a / gcd(x, y)) * b;
}

constexpr int maxFibIndex = 92;  // F(93) exceeds signed 64-bit range.

long long fibCached(int n, long long (&memo)[maxFibIndex + 1]) {
    if (n == 1 || n == 2) return 1;
    if (memo[n] == 0) {
        long long previous = fibCached(n - 1, memo);
        memo[n] = previous + fibCached(n - 2, memo);
    }
    return memo[n];
}

long long fib(int n) {
    if (n < 1 || n > maxFibIndex) return -1;
    long long memo[maxFibIndex + 1] = {};
    return fibCached(n, memo);
}

int checkedMultiply(int x, int y) {
    long long product = static_cast<long long>(x) * y;
    if (product < numeric_limits<int>::min() ||
        product > numeric_limits<int>::max())
        throw overflow_error("Power is outside the int range.");
    return static_cast<int>(product);
}

int getPower(int x, int y) {
    if (y < 0) return 0;
    if (y == 0) return 1;
    int half = getPower(x, y / 2);
    int square = checkedMultiply(half, half);
    return y % 2 == 0 ? square : checkedMultiply(square, x);
}

double getPower(double x, int y) {
    if (y == 0) return 1.0;
    if (x == 0.0 && y < 0)
        throw domain_error("Zero cannot be raised to a negative power.");
    // Halving a negative exponent also works for INT_MIN.
    double half = getPower(x, y / 2);
    double square = half * half;
    if (y % 2 == 0) return square;
    return y > 0 ? square * x : square / x;
}

int main() {
    cout << "1: 3-7 Division       2: 3-9 Prime test\n"
         << "3: 3-10 GCD and LCM  4: 3-13 Fibonacci\n"
         << "5: 3-15 Power        0: Exit\n";

    int choice = 0;
    for (;;) {
        cout << "Select an exercise (0-5):\n";
        if (!(cin >> choice)) return cin.eof() ? 0 : 1;

        switch (choice) {
        case 0:
            return 0;
        case 1: {
            int x = 0, y = 0;
            const int maximum = numeric_limits<unsigned short int>::max();
            cout << "Enter x and y (0-" << maximum << "):\n";
            if (!(cin >> x >> y) || x < 0 || x > maximum ||
                y < 0 || y > maximum) {
                cout << "Invalid unsigned short input.\n";
                return 1;
            }
            try {
                short int result = divide(static_cast<unsigned short int>(x),
                                          static_cast<unsigned short int>(y));
                cout << "Quotient: " << result << '\n';
            } catch (const overflow_error& error) {
                cout << error.what() << '\n';
            }
            break;
        }
        case 2: {
            int n = 0;
            cout << "Enter an integer n:\n";
            if (!(cin >> n)) return 1;
            cout << n << (isPrime(n) ? " is prime.\n" : " is not prime.\n");
            break;
        }
        case 3: {
            int x = 0, y = 0;
            cout << "Enter two integers x and y:\n";
            if (!(cin >> x >> y)) return 1;
            cout << "GCD: " << gcd(x, y) << ", LCM: " << lcm(x, y) << '\n';
            break;
        }
        case 4: {
            int n = 0;
            cout << "Enter n (1-" << maxFibIndex << "):\n";
            if (!(cin >> n)) return 1;
            long long result = fib(n);
            if (result == -1)
                cout << "Fibonacci index must be 1-" << maxFibIndex << ".\n";
            else
                cout << "F(" << n << ") = " << result << '\n';
            break;
        }
        case 5: {
            int a = 0, m = 0;
            double b = 0.0;
            cout << "Enter integer a, real b, and integer exponent m:\n";
            if (!(cin >> a >> b >> m)) return 1;
            try {
                int result = getPower(a, m);
                cout << "a^m (int): " << result << '\n';
            } catch (const overflow_error& error) {
                cout << "a^m (int): " << error.what() << '\n';
            }

            cout << setprecision(15);
            try {
                double result = getPower(b, m);
                cout << "b^m (double): " << result << '\n';
            } catch (const domain_error& error) {
                cout << "b^m (double): " << error.what() << '\n';
            }
            try {
                double result = getPower(static_cast<double>(a), m);
                cout << "a^m (double): " << result << '\n';
            } catch (const domain_error& error) {
                cout << "a^m (double): " << error.what() << '\n';
            }
            break;
        }
        default:
            cout << "Choose a number from 0 to 5.\n";
        }
    }
}
