#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> parseBig(const string& s) {
    vector<int> a;
    for (int i = static_cast<int>(s.length()) - 1; i >= 0; i--) {
        a.push_back(s[i] - '0');
    }
    return a;
}

void printBig(const vector<int>& a) {
    int i = static_cast<int>(a.size()) - 1;
    while (i > 0 && a[i] == 0) {
        i--;
    }
    for (; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}

int compareBig(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) {
        return a.size() > b.size() ? 1 : -1;
    }
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            return a[i] > b[i] ? 1 : -1;
        }
    }
    return 0;
}

vector<int> addBig(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    int carry = 0;
    size_t n = max(a.size(), b.size());
    for (size_t i = 0; i < n || carry; i++) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        c.push_back(sum % 10);
        carry = sum / 10;
    }
    return c;
}

vector<int> subBig(const vector<int>& a, const vector<int>& b) {
    vector<int> c = a;
    int carry = 0;
    for (size_t i = 0; i < b.size() || carry; i++) {
        long long cur = c[i] - carry - (i < b.size() ? b[i] : 0);
        if (cur < 0) {
            cur += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        c[i] = static_cast<int>(cur);
    }
    while (c.size() > 1 && c.back() == 0) {
        c.pop_back();
    }
    return c;
}

int main() {
    string s1, s2;
    if (!(cin >> s1 >> s2)) {
        s1 = "987654321098765";
        s2 = "123456789012345";
    }
    vector<int> a = parseBig(s1);
    vector<int> b = parseBig(s2);

    vector<int> sum = addBig(a, b);
    printBig(sum);

    int cmp = compareBig(a, b);
    if (cmp >= 0) {
        vector<int> diff = subBig(a, b);
        printBig(diff);
    } else {
        vector<int> diff = subBig(b, a);
        cout << "-";
        printBig(diff);
    }
    return 0;
}
