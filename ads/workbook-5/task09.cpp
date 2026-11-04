#include <iostream>

using namespace std;

void hanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, fromRod, auxRod, toRod);
    cout << fromRod << " -> " << toRod << endl;
    hanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n;
    if (!(cin >> n)) {
        n = 3;
    }
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
