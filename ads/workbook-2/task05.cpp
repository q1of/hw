#include <iostream>
#include <string>

using namespace std;

int main() {
    long long val;
    if (!(cin >> val)) {
        val = 14563;
    }
    for (int i = 0; i < 10; i++) {
        long long sq = val * val;
        string s = to_string(sq);
        while (s.length() < 10) {
            s = "0" + s;
        }
        int start = static_cast<int>(s.length() - 5) / 2;
        string mid = s.substr(start, 5);
        val = stoll(mid);
        cout << val << endl;
    }
    return 0;
}
