#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void shakerSort(vector<int>& arr) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    while (left < right) {
        int lastSwap = left;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                lastSwap = i;
            }
        }
        right = lastSwap;

        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                lastSwap = i;
            }
        }
        left = lastSwap;
    }
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8, 0, 2};
    shakerSort(arr);
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
