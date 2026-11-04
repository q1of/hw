#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void fermatFactor(long long n, vector<long long>& factors) {
    if (n <= 1) return;
    if (isPrime(n)) {
        factors.push_back(n);
        return;
    }
    if (n % 2 == 0) {
        factors.push_back(2);
        fermatFactor(n / 2, factors);
        return;
    }
    long long x = static_cast<long long>(ceil(sqrt(n)));
    while (true) {
        long long y2 = x * x - n;
        long long y = static_cast<long long>(round(sqrt(y2)));
        if (y * y == y2) {
            long long a = x - y;
            long long b = x + y;
            if (a == 1) {
                factors.push_back(n);
                return;
            }
            fermatFactor(a, factors);
            fermatFactor(b, factors);
            return;
        }
        x++;
    }
}

int main() {
    long long n = 10059;
    vector<long long> rawFactors;
    fermatFactor(n, rawFactors);
    map<long long, int> factors;
    for (size_t i = 0; i < rawFactors.size(); i++) {
        factors[rawFactors[i]]++;
    }
    cout << n << " = ";
    bool first = true;
    for (map<long long, int>::const_iterator it = factors.begin(); it != factors.end(); ++it) {
        if (!first) cout << " * ";
        cout << it->first;
        if (it->second > 1) cout << "^" << it->second;
        first = false;
    }
    cout << endl;
    return 0;
}
