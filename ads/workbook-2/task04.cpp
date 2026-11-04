#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool lucasLehmer(int p) {
    if (p == 2) return true;
    if (!isPrime(p)) return false;
    unsigned long long mp = (1ULL << p) - 1;
    unsigned long long s = 4;
    for (int i = 0; i < p - 2; i++) {
        s = (s * s - 2) % mp;
    }
    return s == 0;
}

int main() {
    int p = 7;
    unsigned long long mp = (1ULL << p) - 1;
    bool prime = lucasLehmer(p);
    cout << "M_" << p << " = " << mp << " is " << (prime ? "prime" : "composite") << endl;
    return 0;
}
