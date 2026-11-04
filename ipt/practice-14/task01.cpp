#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) return 0;
    stack<char> st;
    bool ok = true;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                ok = false;
                break;
            }
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                ok = false;
                break;
            }
            st.pop();
        } else if (c == '}') {
            if (st.empty() || st.top() != '{') {
                ok = false;
                break;
            }
            st.pop();
        }
    }
    if (ok && st.empty()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
