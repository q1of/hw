#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    if (!(cin >> s1 >> s2)) {
        s1 = "10110";
        s2 = "01101";
    }
    unsigned long long a = stoull(s1, nullptr, 2);
    unsigned long long b = stoull(s2, nullptr, 2);

    int step = 1;
    cout << "Step 0: " << a << " " << b << endl;
    while (b != 0) {
        unsigned long long sum = a ^ b;
        unsigned long long carry = (a & b) << 1;
        a = sum;
        b = carry;
        cout << "Step " << step++ << ": sum=" << a << " carry=" << b << endl;
    }
    cout << a << endl;
    return 0;
}
