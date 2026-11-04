#include <iostream>
#include <cmath>

using namespace std;

int gcdRecursive(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b) return gcdRecursive(a - b, b);
    return gcdRecursive(a, b - a);
}

int main() {
    int a = 48;
    int b = 18;
    int result = gcdRecursive(a, b);
    cout << "GCD(" << a << ", " << b << ") = " << result << endl;
    return 0;
}
