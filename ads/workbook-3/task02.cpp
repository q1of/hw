#include <iostream>
#include <string>

using namespace std;

string toBinaryString(unsigned long long n) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}

int main() {
    unsigned long long a = 0b1101011;
    unsigned long long b = 0b1011101;
    int step = 1;

    cout << "Initial: a = " << toBinaryString(a) << ", b = " << toBinaryString(b) << endl;

    while (b != 0) {
        unsigned long long partialSum = a ^ b;
        unsigned long long carry = (a & b) << 1;
        cout << "Step " << step << ": sum = " << toBinaryString(partialSum)
             << ", carry = " << toBinaryString(carry) << endl;
        a = partialSum;
        b = carry;
        step++;
    }

    cout << "Result: " << toBinaryString(a) << endl;
    return 0;
}
