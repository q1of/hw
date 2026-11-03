#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MinStack {
private:
    vector<pair<int, int>> data;

public:
    void push(int x) {
        int cur_min = empty() ? x : min(x, data.back().second);
        data.push_back({x, cur_min});
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    int top() const {
        return data.back().first;
    }

    int get_min() const {
        return data.back().second;
    }

    int min_element() const {
        return get_min();
    }

    bool empty() const {
        return data.empty();
    }
};

int main() {
    MinStack s;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "push") {
            int x;
            if (cin >> x) {
                s.push(x);
            }
        } else if (cmd == "pop") {
            s.pop();
        } else if (cmd == "top") {
            if (!s.empty()) {
                cout << s.top() << endl;
            }
        } else if (cmd == "min" || cmd == "get_min") {
            if (!s.empty()) {
                cout << s.get_min() << endl;
            }
        } else if (cmd == "empty") {
            cout << (s.empty() ? "true" : "false") << endl;
        }
    }
    return 0;
}
