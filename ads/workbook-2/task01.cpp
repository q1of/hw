#include <iostream>
#include <cmath>

using namespace std;

int gcdSub(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0) return b;
    if (b == 0) return a;
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int gcdFour(int a, int b, int c, int d) {
    return gcdSub(gcdSub(gcdSub(a, b), c), d);
}

int main() {
    int a = 48, b = 64, c = 80, d = 96;
    int result = gcdFour(a, b, c, d);
    cout << "GCD: " << result << endl;
    return 0;
}
