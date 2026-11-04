#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return acos((1.0 - x * x) / (1.0 + x * x)) - x;
}

int main() {
    double L = 2.0;
    double R = 3.0;
    double eps = 0.0001;
    int shag = 0;
    double B = 0.0;

    while (R - L > eps) {
        shag++;
        B = (L + R) / 2.0;
        if (f(L) * f(B) < 0) {
            R = B;
        } else {
            L = B;
        }
        cout << shag << " " << B << endl;
    }

    cout << B << endl;
    return 0;
}
