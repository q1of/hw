#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << "Ingredient " << n << " move from " << from << " to " << to << endl;
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);
    return 0;
}
