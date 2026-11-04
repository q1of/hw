#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printBig(const vector<int>& a) {
    int i = static_cast<int>(a.size()) - 1;
    while (i > 0 && a[i] == 0) i--;
    for (; i >= 0; i--) cout << a[i];
    cout << endl;
}

int main() {
    string s1, s2;
    if (!(cin >> s1 >> s2)) {
        s1 = "789";
        s2 = "456";
    }
    vector<int> a, b;
    for (int i = static_cast<int>(s1.length()) - 1; i >= 0; i--) a.push_back(s1[i] - '0');
    for (int i = static_cast<int>(s2.length()) - 1; i >= 0; i--) b.push_back(s2[i] - '0');

    int step = 1;
    while (true) {
        bool bNonZero = false;
        for (int x : b) {
            if (x != 0) {
                bNonZero = true;
                break;
            }
        }
        if (!bNonZero) break;

        size_t n = max(a.size(), b.size());
        while (a.size() < n) a.push_back(0);
        while (b.size() < n) b.push_back(0);

        vector<int> sum(n, 0);
        vector<int> carry(n + 1, 0);
        for (size_t i = 0; i < n; i++) {
            int total = a[i] + b[i];
            sum[i] = total % 10;
            carry[i + 1] = total / 10;
        }
        a = sum;
        b = carry;
        cout << "Step " << step++ << ": sum=";
        printBig(a);
    }
    printBig(a);
    return 0;
}
