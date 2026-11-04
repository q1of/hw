#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return acos((1.0 - x * x) / (1.0 + x * x)) - x;
}

double bisectionRecursive(double L, double R, double eps, int step) {
    double B = (L + R) / 2.0;
    cout << step << " " << B << endl;
    if (R - L <= eps) {
        return B;
    }
    if (f(L) * f(B) < 0) {
        return bisectionRecursive(L, B, eps, step + 1);
    }
    return bisectionRecursive(B, R, eps, step + 1);
}

int main() {
    double root = bisectionRecursive(2.0, 3.0, 0.0001, 1);
    cout << "Root: " << root << endl;
    return 0;
}
