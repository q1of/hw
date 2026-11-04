#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    vector<int> primes;
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}

map<int, int> factorize(int n) {
    map<int, int> factors;
    int limit = 2;
    while (limit * limit <= n) {
        limit++;
    }
    vector<int> primes = sieve(limit);
    int temp = n;
    for (size_t i = 0; i < primes.size(); i++) {
        int p = primes[i];
        if (p * p > temp) break;
        if (temp % p == 0) {
            int count = 0;
            while (temp % p == 0) {
                count++;
                temp /= p;
            }
            factors[p] = count;
        }
    }
    if (temp > 1) {
        factors[temp] = 1;
    }
    return factors;
}

int main() {
    int n = 1260;
    map<int, int> factors = factorize(n);
    cout << n << " = ";
    bool first = true;
    for (map<int, int>::const_iterator it = factors.begin(); it != factors.end(); ++it) {
        if (!first) cout << " * ";
        cout << it->first;
        if (it->second > 1) cout << "^" << it->second;
        first = false;
    }
    cout << endl;
    return 0;
}
