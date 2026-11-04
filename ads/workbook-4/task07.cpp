#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void cocktailSort(vector<int>& arr) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        right--;
        for (int i = right - 1; i >= left; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        left++;
    }
}

void insertionSort(vector<int>& arr) {
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

void selectionSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) swap(arr[i], arr[minIdx]);
    }
}

void shellSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void gnomeSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    int index = 0;
    while (index < n) {
        if (index == 0 || arr[index] >= arr[index - 1]) index++;
        else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}

template <typename Func>
long long measure(Func sortFunc, vector<int> arr) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

int main() {
    mt19937 gen(42);
    uniform_int_distribution<int> dis(1, 100000);

    int smallSize = 100;
    int largeSize = 5000;

    vector<int> smallArr(smallSize);
    for (int i = 0; i < smallSize; i++) smallArr[i] = dis(gen);

    vector<int> largeArr(largeSize);
    for (int i = 0; i < largeSize; i++) largeArr[i] = dis(gen);

    cout << "Array size: " << smallSize << endl;
    cout << "Bubble sort: " << measure(bubbleSort, smallArr) << " us" << endl;
    cout << "Cocktail sort: " << measure(cocktailSort, smallArr) << " us" << endl;
    cout << "Insertion sort: " << measure(insertionSort, smallArr) << " us" << endl;
    cout << "Selection sort: " << measure(selectionSort, smallArr) << " us" << endl;
    cout << "Shell sort: " << measure(shellSort, smallArr) << " us" << endl;
    cout << "Gnome sort: " << measure(gnomeSort, smallArr) << " us" << endl;

    cout << "\nArray size: " << largeSize << endl;
    cout << "Bubble sort: " << measure(bubbleSort, largeArr) << " us" << endl;
    cout << "Cocktail sort: " << measure(cocktailSort, largeArr) << " us" << endl;
    cout << "Insertion sort: " << measure(insertionSort, largeArr) << " us" << endl;
    cout << "Selection sort: " << measure(selectionSort, largeArr) << " us" << endl;
    cout << "Shell sort: " << measure(shellSort, largeArr) << " us" << endl;
    cout << "Gnome sort: " << measure(gnomeSort, largeArr) << " us" << endl;

    return 0;
}
