#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return acos((1.0 - x * x) / (1.0 + x * x)) - x;
}

int main() {
    double a = 2.0;
    double b = 3.0;
    double eps = 0.0001;
    double xk = a;
    double xprev = a;
    int shag = 0;

    do {
        shag++;
        xk = a - f(a) * (b - a) / (f(b) - f(a));
        cout << shag << " " << xk << endl;

        if (f(xk) == 0.0) {
            break;
        }

        if (f(xk) * f(b) > 0) {
            b = xk;
        } else {
            a = xk;
        }

        if (shag > 1 && abs(xk - xprev) <= eps) {
            break;
        }
        xprev = xk;
    } while (true);

    cout << xk << endl;
    return 0;
}
