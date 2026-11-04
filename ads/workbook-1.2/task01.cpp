#include <iostream>
#include <vector>

using namespace std;

int searchAndInsert(vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    arr.insert(arr.begin() + left, target);
    return left;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 15;
    int pos = searchAndInsert(arr, target);
    cout << pos << endl;
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
