#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> multiplyColumn(const string& s1, const string& s2) {
    int n = static_cast<int>(s1.length());
    int m = static_cast<int>(s2.length());
    vector<int> res(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = mul + res[p2];
            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }
    return res;
}

int main() {
    string s1, s2;
    if (!(cin >> s1 >> s2)) {
        s1 = "123456789";
        s2 = "987654321";
    }
    vector<int> res = multiplyColumn(s1, s2);
    size_t i = 0;
    while (i < res.size() - 1 && res[i] == 0) {
        i++;
    }
    for (; i < res.size(); i++) {
        cout << res[i];
    }
    cout << endl;
    return 0;
}
