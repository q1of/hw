#include <iostream>

using namespace std;

void divideBinary(long long a, long long b, long long& q, long long& r) {
    if (b == 0) return;
    long long low = 0;
    long long high = a;
    q = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid <= a / b) {
            q = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    r = a - q * b;
}

int main() {
    long long a, b;
    if (!(cin >> a >> b)) {
        a = 987654321;
        b = 12345;
    }
    long long q = 0, r = 0;
    divideBinary(a, b, q, r);
    cout << "Quotient: " << q << endl;
    cout << "Remainder: " << r << endl;
    return 0;
}
