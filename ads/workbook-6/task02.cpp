#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    string s;
    if (!getline(cin, s) || s.empty()) {
        s = "hello world";
    }
    unordered_map<char, int> freq;
    vector<char> order;
    for (char c : s) {
        if (freq[c] == 0) {
            order.push_back(c);
        }
        freq[c]++;
    }
    for (char c : order) {
        cout << c << ": " << freq[c] << endl;
    }
    return 0;
}
