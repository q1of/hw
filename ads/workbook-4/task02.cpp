#include <iostream>
#include <vector>

using namespace std;

void cocktailSort(vector<int>& arr) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        right--;
        for (int i = right - 1; i >= left; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        left++;
    }
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8, 0, 2};
    cocktailSort(arr);
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    cout << endl;
    return 0;
}
