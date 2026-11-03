#include <iostream>

using namespace std;

long long power(long long a, long long n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return power(a * a, n / 2);
    }
    return a * power(a, n - 1);
}

int main() {
    long long a, n;
    cin >> a >> n;
    cout << power(a, n) << endl;
    return 0;
}
