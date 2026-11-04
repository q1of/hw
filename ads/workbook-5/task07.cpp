#include <iostream>

using namespace std;

long long sumDigits(long long n) {
    if (n < 0) {
        n = -n;
    }
    if (n < 10) {
        return n;
    }
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    long long n;
    if (!(cin >> n)) {
        n = 123456789;
    }
    cout << sumDigits(n) << endl;
    return 0;
}
