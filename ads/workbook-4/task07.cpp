#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& a) {
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n - 1; i++) {
        bool sw = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) { swap(a[j], a[j + 1]); sw = true; }
        }
        if (!sw) break;
    }
}

void shakerSort(vector<int>& a) {
    int left = 0, right = static_cast<int>(a.size()) - 1;
    while (left < right) {
        int ls = left;
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) { swap(a[i], a[i + 1]); ls = i; }
        }
        right = ls;
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) { swap(a[i], a[i - 1]); ls = i; }
        }
        left = ls;
    }
}

void insertionSort(vector<int>& a) {
    int n = static_cast<int>(a.size());
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}

void selectionSort(vector<int>& a) {
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        if (minIdx != i) swap(a[i], a[minIdx]);
    }
}

void shellSort(vector<int>& a) {
    int n = static_cast<int>(a.size());
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i], j = i;
            while (j >= gap && a[j - gap] > temp) { a[j] = a[j - gap]; j -= gap; }
            a[j] = temp;
        }
    }
}

void gnomeSort(vector<int>& a) {
    int idx = 0, n = static_cast<int>(a.size());
    while (idx < n) {
        if (idx == 0 || a[idx] >= a[idx - 1]) idx++;
        else { swap(a[idx], a[idx - 1]); idx--; }
    }
}

template <typename Func>
long long measure(Func sortFunc, vector<int> arr) {
    auto t1 = chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto t2 = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
}

int main() {
    mt19937 gen(42);
    uniform_int_distribution<int> dist(1, 100000);

    vector<int> small(100);
    for (int& x : small) x = dist(gen);

    cout << "Small (100 elements):" << endl;
    cout << "Bubble:    " << measure(bubbleSort, small) << " mcs" << endl;
    cout << "Shaker:    " << measure(shakerSort, small) << " mcs" << endl;
    cout << "Insertion: " << measure(insertionSort, small) << " mcs" << endl;
    cout << "Selection: " << measure(selectionSort, small) << " mcs" << endl;
    cout << "Shell:     " << measure(shellSort, small) << " mcs" << endl;
    cout << "Gnome:     " << measure(gnomeSort, small) << " mcs" << endl;

    vector<int> large(50000);
    for (int& x : large) x = dist(gen);
    cout << "Large (50000 elements):" << endl;
    cout << "Shell:     " << measure(shellSort, large) << " mcs" << endl;
    return 0;
}
