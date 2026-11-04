#include <iostream>
#include <vector>

using namespace std;

void gnomeSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    int index = 0;
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
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    cout << endl;
    return 0;
}
