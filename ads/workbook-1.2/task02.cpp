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
    int peak1 = findMountainPeak(arr1);
    if (peak1 != -1) {
        cout << "Peak index: " << peak1 << ", value: " << arr1[peak1] << endl;
    } else {
        cout << "Not a mountain array" << endl;
    }

    vector<int> arr2 = {1, 2, 3, 4, 5};
    int peak2 = findMountainPeak(arr2);
    if (peak2 != -1) {
        cout << "Peak index: " << peak2 << ", value: " << arr2[peak2] << endl;
    } else {
        cout << "Not a mountain array" << endl;
    }

    return 0;
}
