#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countSmaller(const vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    vector<int> counts(n, 0);
    vector<int> sorted;
    for (int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
        int idx = static_cast<int>(it - sorted.begin());
        counts[i] = idx;
        sorted.insert(it, nums[i]);
    }
    return counts;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};
    vector<int> counts = countSmaller(nums);
    for (int c : counts) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
