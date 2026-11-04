#include <iostream>

using namespace std;

long long gcdRecursive(long long a, long long b) {
    if (a == b) {
        return a;
    }
    if (a > b) {
        return gcdRecursive(a - b, b);
    }
    return gcdRecursive(a, b - a);
}

int main() {
    long long a, b;
    if (!(cin >> a >> b)) {
        a = 64;
        b = 48;
    }
    cout << gcdRecursive(a, b) << endl;
    return 0;
}
