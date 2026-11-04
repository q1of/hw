#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> strToBig(const string& s) {
    vector<int> arr;
    for (int i = static_cast<int>(s.length()) - 1; i >= 0; i--) {
        arr.push_back(s[i] - '0');
    }
    return arr;
}

string bigToStr(vector<int> arr) {
    while (arr.size() > 1 && arr.back() == 0) {
        arr.pop_back();
    }
    string s = "";
    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; i--) {
        s += to_string(arr[i]);
    }
    return s;
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
    vector<int> res;
    int carry = 0;
    size_t maxLen = max(a.size(), b.size());
    for (size_t i = 0; i < maxLen || carry; i++) {
        int d1 = i < a.size() ? a[i] : 0;
        int d2 = i < b.size() ? b[i] : 0;
        int total = d1 + d2 + carry;
        res.push_back(total % 10);
        carry = total / 10;
    }
    return res;
}

vector<int> subBig(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int borrow = 0;
    for (size_t i = 0; i < a.size(); i++) {
        int d1 = a[i];
        int d2 = i < b.size() ? b[i] : 0;
        int diff = d1 - d2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_back(diff);
    }
    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }
    return res;
}

int main() {
    string s1 = "987654321098765432109876543210";
    string s2 = "12345678901234567890123456789";
    vector<int> a = strToBig(s1);
    vector<int> b = strToBig(s2);

    cout << "A: " << s1 << endl;
    cout << "B: " << s2 << endl;
    cout << "A + B: " << bigToStr(addBig(a, b)) << endl;

    if (compareBig(a, b) >= 0) {
        cout << "A - B: " << bigToStr(subBig(a, b)) << endl;
    } else {
        cout << "B - A: " << bigToStr(subBig(b, a)) << endl;
    }

    return 0;
}
