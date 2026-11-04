#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

vector<int> multiplyColumn(const vector<int>& a, const vector<int>& b) {
    int n = static_cast<int>(a.size());
    int m = static_cast<int>(b.size());
    vector<int> res(n + m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i + j] += a[i] * b[j];
        }
    }
    int carry = 0;
    for (size_t k = 0; k < res.size(); k++) {
        int total = res[k] + carry;
        res[k] = total % 10;
        carry = total / 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

vector<int> addVec(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int carry = 0;
    size_t n = max(a.size(), b.size());
    for (size_t i = 0; i < n || carry; i++) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        res.push_back(sum % 10);
        carry = sum / 10;
    }
    return res;
}

vector<int> subVec(const vector<int>& a, const vector<int>& b) {
    vector<int> res = a;
    int carry = 0;
    for (size_t i = 0; i < b.size() || carry; i++) {
        int cur = res[i] - carry - (i < b.size() ? b[i] : 0);
        if (cur < 0) {
            cur += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res[i] = cur;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    size_t n = max(a.size(), b.size());
    if (n <= 32) {
        return multiplyColumn(a, b);
    }
    size_t k = n / 2;
    vector<int> a0(a.begin(), a.begin() + min(k, a.size()));
    vector<int> a1(a.begin() + min(k, a.size()), a.end());
    vector<int> b0(b.begin(), b.begin() + min(k, b.size()));
    vector<int> b1(b.begin() + min(k, b.size()), b.end());

    vector<int> z0 = karatsuba(a0, b0);
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z1 = karatsuba(addVec(a0, a1), addVec(b0, b1));
    z1 = subVec(subVec(z1, z0), z2);

    vector<int> res = z0;
    vector<int> shift1(k, 0);
    shift1.insert(shift1.end(), z1.begin(), z1.end());
    vector<int> shift2(2 * k, 0);
    shift2.insert(shift2.end(), z2.begin(), z2.end());

    return addVec(addVec(res, shift1), shift2);
}

int main() {
    vector<int> a(100, 7);
    vector<int> b(100, 9);

    auto t1 = chrono::high_resolution_clock::now();
    vector<int> r1 = multiplyColumn(a, b);
    auto t2 = chrono::high_resolution_clock::now();
    auto colTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

    t1 = chrono::high_resolution_clock::now();
    vector<int> r2 = karatsuba(a, b);
    t2 = chrono::high_resolution_clock::now();
    auto karTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

    cout << "Column: " << colTime << " mcs" << endl;
    cout << "Karatsuba: " << karTime << " mcs" << endl;
    return 0;
}
