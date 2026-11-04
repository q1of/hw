#include <iostream>
#include <vector>

using namespace std;

int findMountainPeak(const vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    if (n < 3) {
        return -1;
    }
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    int peak = left;
    if (peak == 0 || peak == n - 1) {
        return -1;
    }
    for (int i = 0; i < peak; i++) {
        if (arr[i] >= arr[i + 1]) {
            return -1;
        }
    }
    for (int i = peak; i < n - 1; i++) {
        if (arr[i] <= arr[i + 1]) {
            return -1;
        }
    }
    return peak;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 8, 12, 9, 6, 2, 0};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << findMountainPeak(arr1) << endl;
    cout << findMountainPeak(arr2) << endl;
    return 0;
}
