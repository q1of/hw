#include <iostream>
#include <vector>

using namespace std;

int searchAndInsert(vector<int>& arr, int target, bool& found) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            found = true;
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
    bool found = false;

    int pos = searchAndInsert(arr, target, found);

    if (found) {
        cout << "Element found at position: " << pos << endl;
    } else {
        cout << "Element not found. Inserted at position: " << pos << endl;
    }

    cout << "Array: ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    cout << endl;

    return 0;
}
