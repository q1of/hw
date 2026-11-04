#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return acos((1.0 - x * x) / (1.0 + x * x)) - x;
}

double bisectionRecursive(double L, double R, double eps, int& step) {
    step++;
    double B = (L + R) / 2.0;
    cout << step << " " << B << endl;
    if (R - L <= eps) {
        return B;
    }
    if (f(L) * f(B) < 0) {
        return bisectionRecursive(L, B, eps, step);
    }
    return bisectionRecursive(B, R, eps, step);
}

int main() {
    double L = 2.0;
    double R = 3.0;
    double eps = 0.0001;
    int step = 0;
    double root = bisectionRecursive(L, R, eps, step);
    cout << root << endl;
    return 0;
}
