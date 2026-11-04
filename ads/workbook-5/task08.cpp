#include <iostream>

using namespace std;

long long F(long long n) {
    if (n <= 1) {
        return n;
    }
    if (n % 2 == 0) {
        return F(n / 2);
    }
    return F(n / 2) + F(n / 2 + 1);
}

int main() {
    long long n;
    if (!(cin >> n)) {
        n = 15;
    }
    cout << F(n) << endl;
    return 0;
}
