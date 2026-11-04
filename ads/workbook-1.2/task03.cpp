#include <iostream>
#include <vector>

using namespace std;

void countNegPos(const vector<int>& arr, int& negCount, int& posCount) {
    int n = static_cast<int>(arr.size());

    int left = 0;
    int right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    negCount = left;

    left = 0;
    right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    posCount = n - left;
}

int main() {
    vector<int> arr = {-15, -10, -8, -4, -1, 0, 0, 2, 5, 7, 9, 14, 22, 35};
    int negCount = 0;
    int posCount = 0;

    countNegPos(arr, negCount, posCount);

    cout << "Negative count: " << negCount << endl;
    cout << "Positive count: " << posCount << endl;

    if (posCount > negCount) {
        cout << "More positive numbers: " << posCount << endl;
    } else if (negCount > posCount) {
        cout << "More negative numbers: " << negCount << endl;
    } else {
        cout << "Equal count: " << posCount << endl;
    }

    return 0;
}
