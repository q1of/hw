#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void gnomeSort(vector<int>& arr) {
    int index = 0;
    int n = static_cast<int>(arr.size());
    while (index < n) {
        if (index == 0 || arr[index] >= arr[index - 1]) {
            index++;
        } else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}

int main() {
    vector<int> arr = {34, 2, 10, -9};
    gnomeSort(arr);
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
