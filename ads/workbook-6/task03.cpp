#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> nums = {-1, 2, 3, 4, 7};
    int target = 5;
    unordered_map<int, int> numToIdx;
    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        int complement = target - nums[i];
        if (numToIdx.find(complement) != numToIdx.end()) {
            cout << numToIdx[complement] << " " << i << endl;
            return 0;
        }
        numToIdx[nums[i]] = i;
    }
    return 0;
}
