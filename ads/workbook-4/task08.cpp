#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

int binarySearchPosition(const vector<int>& arr, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == arr[mid]) return mid + 1;
        if (item > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

void binaryInsertionSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; i++) {
        int selected = arr[i];
        int j = i - 1;
        int loc = binarySearchPosition(arr, selected, 0, j);
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

void standardInsertionSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    mt19937 gen(42);
    uniform_int_distribution<int> dis(1, 100000);
    int size = 5000;
    vector<int> a(size), b(size);
    for (int i = 0; i < size; i++) {
        a[i] = dis(gen);
        b[i] = a[i];
    }

    auto startStd = chrono::high_resolution_clock::now();
    standardInsertionSort(a);
    auto endStd = chrono::high_resolution_clock::now();
    auto timeStd = chrono::duration_cast<chrono::microseconds>(endStd - startStd).count();

    auto startBin = chrono::high_resolution_clock::now();
    binaryInsertionSort(b);
    auto endBin = chrono::high_resolution_clock::now();
    auto timeBin = chrono::duration_cast<chrono::microseconds>(endBin - startBin).count();

    cout << "Standard insertion sort: " << timeStd << " us" << endl;
    cout << "Binary insertion sort: " << timeBin << " us" << endl;
    return 0;
}
