#include <iostream>

using namespace std;

long long fibonacci(int n) {
    if (n <= 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    if (!(cin >> n)) {
        n = 10;
    }
    cout << fibonacci(n) << endl;
    return 0;
}
