#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeLPS(const string& pat) {
    int m = static_cast<int>(pat.length());
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> searchKMP(const string& txt, const string& pat) {
    vector<int> occurrences;
    int n = static_cast<int>(txt.length());
    int m = static_cast<int>(pat.length());
    if (m == 0 || n < m) return occurrences;
    vector<int> lps = computeLPS(pat);
    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == m) {
            occurrences.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return occurrences;
}

int main() {
    string txt = "ababcabcabababd";
    string pat = "aba";
    vector<int> res = searchKMP(txt, pat);
    for (size_t k = 0; k < res.size(); k++) {
        cout << res[k] << (k + 1 < res.size() ? " " : "");
    }
    cout << endl;
    return 0;
}
