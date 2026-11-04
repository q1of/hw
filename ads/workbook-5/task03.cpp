#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> buildPrefix(const string& p) {
    int m = static_cast<int>(p.length());
    vector<int> pi(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int> kmpSearch(const string& s, const string& p) {
    vector<int> positions;
    int n = static_cast<int>(s.length());
    int m = static_cast<int>(p.length());
    if (m == 0 || n < m) return positions;

    vector<int> pi = buildPrefix(p);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            j++;
        }
        if (j == m) {
            positions.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }
    return positions;
}

int main() {
    string s = "ababcabcabababd";
    string p = "aba";
    vector<int> positions = kmpSearch(s, p);

    cout << "Pattern \"" << p << "\" found in \"" << s << "\" at positions: ";
    for (size_t i = 0; i < positions.size(); i++) {
        cout << positions[i] << (i + 1 < positions.size() ? ", " : "");
    }
    cout << endl;

    return 0;
}
