#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> setA(a.begin(), a.end());
    unordered_set<int> intersectSet;
    for (int x : b) {
        if (setA.count(x)) {
            intersectSet.insert(x);
        }
    }
    return vector<int>(intersectSet.begin(), intersectSet.end());
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {0, 2, 4, 6, 8};
    vector<int> res = intersection(a, b);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
