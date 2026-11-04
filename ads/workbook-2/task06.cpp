#include <iostream>
#include <vector>

using namespace std;

vector<int> sieveSundaram(int limit) {
    vector<int> primes;
    if (limit < 2) return primes;
    int k = (limit - 1) / 2;
    vector<bool> marked(k + 1, false);
    for (int i = 1; i <= k; i++) {
        for (int j = i; i + j + 2 * i * j <= k; j++) {
            marked[i + j + 2 * i * j] = true;
        }
    }
    primes.push_back(2);
    for (int i = 1; i <= k; i++) {
        if (!marked[i]) {
            primes.push_back(2 * i + 1);
        }
    }
    return primes;
}

int main() {
    int limit = 100;
    vector<int> primes = sieveSundaram(limit);
    cout << "Primes up to " << limit << ": ";
    for (size_t i = 0; i < primes.size(); i++) {
        cout << primes[i] << (i + 1 < primes.size() ? " " : "");
    }
    cout << endl;
    return 0;
}
