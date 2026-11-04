#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

string firstDuplicate(const vector<string>& arr) {
    unordered_set<string> seen;
    for (const string& s : arr) {
        if (seen.find(s) != seen.end()) {
            return s;
        }
        seen.insert(s);
    }
    return "";
}

int main() {
    vector<string> arr = {"a", "b", "c", "d", "c", "e", "f"};
    cout << firstDuplicate(arr) << endl;
    return 0;
}
