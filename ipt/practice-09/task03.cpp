#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string to_bin(string num) {
    if (num == "0") {
        return "0";
    }
    string bin = "";
    while (!num.empty()) {
        int rem = 0;
        string next = "";
        for (char c : num) {
            int cur = rem * 10 + (c - '0');
            int q = cur / 2;
            rem = cur % 2;
            if (!(next.empty() && q == 0)) {
                next += to_string(q);
            }
        }
        bin += (rem + '0');
        num = next;
    }
    string res = "";
    for (int i = (int)bin.length() - 1; i >= 0; i--) {
        res += bin[i];
    }
    return res;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    string s;
    if (getline(in, s)) {
        string res = "";
        int len = s.length();
        for (int i = 0; i < len; ) {
            if (isdigit(s[i])) {
                string num = "";
                while (i < len && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                res += to_bin(num);
            } else {
                res += s[i];
                i++;
            }
        }
        out << res << endl;
        cout << res << endl;
    }
    return 0;
}
