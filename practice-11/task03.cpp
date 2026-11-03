#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, k, l;
    if (!(cin >> n >> k >> l)) return 0;
    map<int, int> count;
    for (int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        count[cost]++;
    }
    vector<int> available;
    for (auto const& [cost, cnt] : count) {
        int take = min(cnt, l);
        for (int i = 0; i < take; i++) {
            available.push_back(cost);
        }
    }
    sort(available.rbegin(), available.rend());
    long long total = 0;
    for (int i = 0; i < k && i < (int)available.size(); i++) {
        total += available[i];
    }
    cout << total << endl;
    return 0;
}
