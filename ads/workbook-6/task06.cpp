#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

char firstUniqueChar(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    for (char c : s) {
        if (freq[c] == 1) {
            return c;
        }
    }
    return '\0';
}

int main() {
    string s = "minimum";
    char c = firstUniqueChar(s);
    if (c != '\0') {
        cout << c << endl;
    }
    return 0;
}
