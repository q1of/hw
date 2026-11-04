#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10) {
        return x * y;
    }
    string sx = to_string(x);
    string sy = to_string(y);
    int n = max(static_cast<int>(sx.length()), static_cast<int>(sy.length()));
    int half = n / 2;
    long long power = 1;
    for (int i = 0; i < half; i++) power *= 10;

    long long a = x / power;
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;

    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long abcd = karatsuba(a + b, c + d);

    return ac * power * power + (abcd - ac - bd) * power + bd;
}

long long schoolMultiply(long long x, long long y) {
    return x * y;
}

int main() {
    long long x = 12345678;
    long long y = 87654321;

    auto startK = chrono::high_resolution_clock::now();
    long long resK = karatsuba(x, y);
    auto endK = chrono::high_resolution_clock::now();
    auto timeK = chrono::duration_cast<chrono::nanoseconds>(endK - startK).count();

    auto startS = chrono::high_resolution_clock::now();
    long long resS = schoolMultiply(x, y);
    auto endS = chrono::high_resolution_clock::now();
    auto timeS = chrono::duration_cast<chrono::nanoseconds>(endS - startS).count();

    cout << "Karatsuba result: " << resK << ", time: " << timeK << " ns" << endl;
    cout << "School result: " << resS << ", time: " << timeS << " ns" << endl;
    return 0;
}
