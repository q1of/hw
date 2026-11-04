#include <iostream>
#include <vector>

using namespace std;

void sieveOfSundaram(int limit) {
    int k = (limit - 1) / 2;
    vector<bool> marked(k + 1, false);
    for (int i = 1; i <= k; i++) {
        int j = i;
        while (i + j + 2 * i * j <= k) {
            marked[i + j + 2 * i * j] = true;
            j++;
        }
    }
    if (limit >= 2) {
        cout << 2 << " ";
    }
    for (int i = 1; i <= k; i++) {
        if (!marked[i]) {
            cout << 2 * i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int limit;
    if (!(cin >> limit)) {
        limit = 50;
    }
    sieveOfSundaram(limit);
    return 0;
}
