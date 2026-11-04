#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

int binarySearch(const vector<int>& a, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == a[mid]) return mid + 1;
        if (item > a[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

void binaryInsertionSort(vector<int>& a) {
    int n = static_cast<int>(a.size());
    for (int i = 1; i < n; i++) {
        int selected = a[i];
        int loc = binarySearch(a, selected, 0, i - 1);
        int j = i - 1;
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

void standardInsertionSort(vector<int>& a) {
    int n = static_cast<int>(a.size());
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    mt19937 gen(42);
    uniform_int_distribution<int> dist(1, 10000);
    vector<int> a(5000), b;
    for (int& x : a) x = dist(gen);
    b = a;

    auto t1 = chrono::high_resolution_clock::now();
    standardInsertionSort(a);
    auto t2 = chrono::high_resolution_clock::now();
    auto stdTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

    t1 = chrono::high_resolution_clock::now();
    binaryInsertionSort(b);
    t2 = chrono::high_resolution_clock::now();
    auto binTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

    cout << "Standard Insertion Sort: " << stdTime << " mcs" << endl;
    cout << "Binary Insertion Sort:   " << binTime << " mcs" << endl;
    return 0;
}
