#include <iostream>

using namespace std;

void hanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 0) return;
    hanoi(n - 1, fromRod, auxRod, toRod);
    cout << "Move disk " << n << " from " << fromRod << " to " << toRod << endl;
    hanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n = 3;
    cout << "Hanoi solution for " << n << " disks:" << endl;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
