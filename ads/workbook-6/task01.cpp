#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers = {86, 90, 27, 29, 38, 30, 40};
    int tableSize = 7;
    vector<int> table(tableSize, -1);

    for (int num : numbers) {
        int idx = num % tableSize;
        while (table[idx] != -1) {
            idx = (idx + 1) % tableSize;
        }
        table[idx] = num;
    }

    for (int i = 0; i < tableSize; i++) {
        cout << i << ": " << table[i] << endl;
    }
    return 0;
}
