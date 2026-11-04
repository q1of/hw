#include <iostream>
#include <vector>

using namespace std;

int bisectLeft(const vector<int>& arr, int x) {
    int left = 0;
    int right = static_cast<int>(arr.size());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

vector<int> countSmallerRight(const vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    vector<int> counts(n, 0);
    vector<int> seen;

    for (int i = n - 1; i >= 0; i--) {
        int idx = bisectLeft(seen, nums[i]);
        counts[i] = idx;
        seen.insert(seen.begin() + idx, nums[i]);
    }

    return counts;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = countSmallerRight(nums);

    cout << "Counts: ";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i + 1 < result.size() ? " " : "");
    }
    cout << endl;

    return 0;
}
