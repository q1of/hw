#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
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

int main() {
    long long n;
    if (!(cin >> n)) {
        n = 360;
    }
    long long temp = n;
    vector<int> primes = sieve(100000);
    map<long long, int> factors;

    for (int p : primes) {
        if (1LL * p * p > temp) {
            break;
        }
        while (temp % p == 0) {
            factors[p]++;
            temp /= p;
        }
    }
    if (temp > 1) {
        factors[temp]++;
    }

    for (const auto& pair : factors) {
        cout << pair.first << "^" << pair.second << " ";
    }
    cout << endl;
    return 0;
}
