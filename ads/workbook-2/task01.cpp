#include <iostream>

using namespace std;

long long gcdSub(long long a, long long b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    long long a, b, c, d;
    if (!(cin >> a >> b >> c >> d)) {
        a = 48;
        b = 64;
        c = 80;
        d = 96;
    }
    long long result = gcdSub(gcdSub(gcdSub(a, b), c), d);
    cout << result << endl;
    return 0;
}
