#include <iostream>

using namespace std;

void divideBinarySearch(unsigned long long a, unsigned long long b, unsigned long long& quotient, unsigned long long& remainder) {
    if (b == 0) {
        quotient = 0;
        remainder = 0;
        return;
    }
    if (a < b) {
        quotient = 0;
        remainder = a;
        return;
    }
    unsigned long long low = 0;
    unsigned long long high = a;
    quotient = 0;
    while (low <= high) {
        unsigned long long mid = low + (high - low) / 2;
        if (mid <= a / b) {
            quotient = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    remainder = a - b * quotient;
}

int main() {
    unsigned long long a = 123456789012345ULL;
    unsigned long long b = 98765ULL;
    unsigned long long q = 0, r = 0;

    divideBinarySearch(a, b, q, r);

    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << "Quotient: " << q << endl;
    cout << "Remainder: " << r << endl;
    return 0;
}
