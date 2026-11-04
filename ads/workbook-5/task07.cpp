#include <iostream>
#include <cmath>

using namespace std;

int sumOfDigits(long long n) {
    n = abs(n);
    if (n < 10) return static_cast<int>(n);
    return static_cast<int>(n % 10) + sumOfDigits(n / 10);
}

int main() {
    long long n = 123456789;
    cout << "Sum of digits of " << n << ": " << sumOfDigits(n) << endl;
    return 0;
}
