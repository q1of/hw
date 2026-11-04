#include <iostream>
#include <vector>

using namespace std;

int countNegatives(const vector<int>& arr) {
    int left = 0;
    int right = static_cast<int>(arr.size());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int countPositives(const vector<int>& arr) {
    int left = 0;
    int right = static_cast<int>(arr.size());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return static_cast<int>(arr.size()) - left;
}

int main() {
    vector<int> arr = {-15, -10, -8, -4, -1, 0, 0, 2, 5, 7, 9, 14, 22, 35};
    int neg = countNegatives(arr);
    int pos = countPositives(arr);
    if (pos > neg) {
        cout << pos << endl;
    } else if (neg > pos) {
        cout << neg << endl;
    } else {
        cout << pos << endl;
    }
    return 0;
}
