#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isNonZero(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] != 0) return true;
    }
    return false;
}

string vecToStr(const vector<int>& v) {
    if (v.empty()) return "0";
    string s = "";
    int i = static_cast<int>(v.size()) - 1;
    while (i > 0 && v[i] == 0) i--;
    for (; i >= 0; i--) {
        s += to_string(v[i]);
    }
    return s;
}

int main() {
    string s1 = "7859";
    string s2 = "4386";

    vector<int> a, b;
    for (int i = static_cast<int>(s1.length()) - 1; i >= 0; i--) a.push_back(s1[i] - '0');
    for (int i = static_cast<int>(s2.length()) - 1; i >= 0; i--) b.push_back(s2[i] - '0');

    int step = 1;
    cout << "Initial: a = " << s1 << ", b = " << s2 << endl;

    while (isNonZero(b)) {
        size_t maxLen = max(a.size(), b.size());
        while (a.size() < maxLen) a.push_back(0);
        while (b.size() < maxLen) b.push_back(0);

        vector<int> sumDigits(maxLen, 0);
        vector<int> carryDigits(maxLen + 1, 0);

        for (size_t k = 0; k < maxLen; k++) {
            int total = a[k] + b[k];
            sumDigits[k] = total % 10;
            carryDigits[k + 1] = total / 10;
        }

        cout << "Step " << step << ": sum = " << vecToStr(sumDigits)
             << ", carry = " << vecToStr(carryDigits) << endl;

        a = sumDigits;
        b = carryDigits;
        step++;
    }

    cout << "Result: " << vecToStr(a) << endl;
    return 0;
}
