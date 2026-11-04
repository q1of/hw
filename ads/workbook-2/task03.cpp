#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

bool isSquare(long long n, long long& root) {
    if (n < 0) return false;
    long long r = static_cast<long long>(round(sqrt(n)));
    if (r * r == n) {
        root = r;
        return true;
    }
    return false;
}

void fermatFactor(long long n, vector<long long>& factors) {
    if (n <= 1) return;
    if (n % 2 == 0) {
        factors.push_back(2);
        fermatFactor(n / 2, factors);
        return;
    }
    long long x = static_cast<long long>(ceil(sqrt(n)));
    long long y = 0;
    while (!isSquare(x * x - n, y)) {
        x++;
    }
    long long a = x - y;
    long long b = x + y;
    if (a == 1) {
        factors.push_back(b);
    } else {
        fermatFactor(a, factors);
        fermatFactor(b, factors);
    }
}

int main() {
    long long n;
    if (!(cin >> n)) {
        n = 105;
    }
    vector<long long> rawFactors;
    fermatFactor(n, rawFactors);
    map<long long, int> counts;
    for (long long f : rawFactors) {
        counts[f]++;
    }
    for (const auto& pair : counts) {
        cout << pair.first << "^" << pair.second << " ";
    }
    cout << endl;
    return 0;
}
