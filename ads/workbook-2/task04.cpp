#include <iostream>

using namespace std;

bool isLucasLehmerPrime(int p) {
    if (p == 2) {
        return true;
    }
    if (p < 2) {
        return false;
    }
    long long m = (1LL << p) - 1;
    long long s = 4;
    for (int i = 0; i < p - 2; i++) {
        s = (s * s - 2) % m;
    }
    return s == 0;
}

int main() {
    int p;
    if (!(cin >> p)) {
        p = 5;
    }
    if (isLucasLehmerPrime(p)) {
        cout << "Prime" << endl;
    } else {
        cout << "Composite" << endl;
    }
    return 0;
}
