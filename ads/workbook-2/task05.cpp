#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    long long seed = 14563;
    long long current = seed;
    for (int i = 1; i <= 10; i++) {
        long long sq = current * current;
        string s = to_string(sq);
        while (s.length() < 10) {
            s = "0" + s;
        }
        int start = (static_cast<int>(s.length()) - 5) / 2;
        string mid = s.substr(start, 5);
        current = stoll(mid);
        cout << i << ": " << setw(5) << setfill('0') << current << endl;
    }
    return 0;
}
