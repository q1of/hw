#include <iostream>

using namespace std;

long long F(long long n) {
    if (n <= 1) return 1;
    if (n % 2 == 0) {
        return F(n / 2);
    }
    return F(n / 2) + F(n / 2 + 1);
}

int main() {
    for (int n = 1; n <= 15; n++) {
        cout << "F(" << n << ") = " << F(n) << endl;
    }
    return 0;
}
