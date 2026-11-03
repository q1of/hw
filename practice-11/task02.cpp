#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can(int m, int n, int d, const vector<int>& a) {
    int count = 0;
    int i = 0;
    while (i < n) {
        count++;
        int j = i;
        while (j < n && a[j] - a[i] <= m) {
            j++;
        }
        i = j;
    }
    return count <= d;
}

int main() {
    int n, d;
    if (!(cin >> n >> d)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int low = 0, high = a[n - 1] - a[0];
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can(mid, n, d, a)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
