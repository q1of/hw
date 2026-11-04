#include <iostream>

using namespace std;

long long fibonacci(int n) {
    if (n == 0 || n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    for (int i = 0; i <= 10; i++) {
        cout << "X_" << i << " = " << fibonacci(i) << endl;
    }
    return 0;
}
