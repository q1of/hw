#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string to_lower_all(const string& s) {
    string res = "";
    int len = s.length();
    for (int i = 0; i < len; ) {
        unsigned char c1 = (unsigned char)s[i];
        if (c1 < 128) {
            if (c1 >= 'A' && c1 <= 'Z') {
                res += (char)(c1 + 32);
            } else {
                res += (char)c1;
            }
            i++;
        } else if (c1 == 0xD0 && i + 1 < len) {
            unsigned char c2 = (unsigned char)s[i + 1];
            if (c2 == 0x81) {
                res += (char)0xD1;
                res += (char)0x91;
            } else if (c2 >= 0x90 && c2 <= 0x9F) {
                res += (char)0xD0;
                res += (char)(c2 + 0x20);
            } else if (c2 >= 0xA0 && c2 <= 0xAF) {
                res += (char)0xD1;
                res += (char)(c2 - 0x20);
            } else {
                res += (char)c1;
                res += (char)c2;
            }
            i += 2;
        } else if (c1 == 0xD1 && i + 1 < len) {
            unsigned char c2 = (unsigned char)s[i + 1];
            res += (char)c1;
            res += (char)c2;
            i += 2;
        } else if (c1 >= 0xC0 && c1 <= 0xDF) {
            res += (char)(c1 + 32);
            i++;
        } else if (c1 == 0xA8) {
            res += (char)0xB8;
            i++;
        } else {
            res += s[i];
            i++;
        }
    }
    return res;
}

bool is_delim(const string& s, int i, int& byte_len) {
    unsigned char c1 = (unsigned char)s[i];
    if (c1 < 128) {
        byte_len = 1;
        if (isspace(c1)) return true;
        string p = ",.!?():;\"'/`~@#$%^&*+=|<>{}[]_";
        if (p.find((char)c1) != string::npos) return true;
        return false;
    }
    if (c1 == 0xE2 && i + 2 < (int)s.length()) {
        unsigned char c2 = (unsigned char)s[i + 1];
        unsigned char c3 = (unsigned char)s[i + 2];
        if (c2 == 0x80 && (c3 == 0x93 || c3 == 0x94 || c3 == 0x98 || c3 == 0x99 || c3 == 0x9C || c3 == 0x9D)) {
            byte_len = 3;
            return true;
        }
    }
    if (c1 == 0xAB || c1 == 0xBB || c1 == 0x96 || c1 == 0x97) {
        byte_len = 1;
        return true;
    }
    if ((c1 == 0xD0 || c1 == 0xD1) && i + 1 < (int)s.length()) {
        byte_len = 2;
        return false;
    }
    byte_len = 1;
    return false;
}

int main() {
    string line;
    vector<string> unique_words;
    set<string> seen;

    while (getline(cin, line)) {
        int len = line.length();
        for (int i = 0; i < len; ) {
            int bl = 0;
            if (line[i] == '-' || is_delim(line, i, bl)) {
                i += bl > 0 ? bl : 1;
            } else {
                int start = i;
                while (i < len) {
                    int d_bl = 0;
                    if (is_delim(line, i, d_bl)) {
                        break;
                    }
                    if (line[i] == '-') {
                        int next_bl = 0;
                        if (i + 1 < len && !is_delim(line, i + 1, next_bl) && line[i + 1] != '-') {
                            i++;
                        } else {
                            break;
                        }
                    } else {
                        i += d_bl > 0 ? d_bl : 1;
                    }
                }
                string word = line.substr(start, i - start);
                string lower_word = to_lower_all(word);
                if (!lower_word.empty() && seen.find(lower_word) == seen.end()) {
                    seen.insert(lower_word);
                    unique_words.push_back(lower_word);
                }
            }
        }
    }

    for (const string& w : unique_words) {
        cout << w << endl;
    }

    return 0;
}
