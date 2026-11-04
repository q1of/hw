#include <iostream>
#include <vector>
#include <string>

using namespace std;

string multiplyColumn(const string& s1, const string& s2) {
    vector<int> a, b;
    for (int i = static_cast<int>(s1.length()) - 1; i >= 0; i--) a.push_back(s1[i] - '0');
    for (int i = static_cast<int>(s2.length()) - 1; i >= 0; i--) b.push_back(s2[i] - '0');

    vector<int> res(a.size() + b.size(), 0);
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < b.size(); j++) {
            res[i + j] += a[i] * b[j];
        }
    }

    int carry = 0;
    for (size_t k = 0; k < res.size(); k++) {
        int total = res[k] + carry;
        res[k] = total % 10;
        carry = total / 10;
    }

    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }

    string s = "";
    for (int i = static_cast<int>(res.size()) - 1; i >= 0; i--) {
        s += to_string(res[i]);
    }
    return s;
}

int main() {
    string s1 = "12345678901234567890";
    string s2 = "98765432109876543210";
    string result = multiplyColumn(s1, s2);
    cout << s1 << " * " << s2 << " = " << result << endl;
    return 0;
}
