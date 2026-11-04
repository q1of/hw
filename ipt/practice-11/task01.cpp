#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        if (!line.empty() && line.find_first_not_of(" \t\r\n") != string::npos) {
            lines.push_back(line);
        }
    }
    if (lines.empty()) return 0;

    int n = 0, m = 0;
    vector<vector<int>> grid;

    stringstream first_ss(lines[0]);
    vector<int> first_row;
    int val;
    while (first_ss >> val) {
        first_row.push_back(val);
    }

    if (first_row.size() == 2 && (int)lines.size() == first_row[0] + 1) {
        n = first_row[0];
        m = first_row[1];
        grid.assign(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            stringstream ss(lines[i + 1]);
            for (int j = 0; j < m; j++) {
                ss >> grid[i][j];
            }
        }
    } else {
        n = lines.size();
        m = first_row.size();
        grid.assign(n, vector<int>(m));
        grid[0] = first_row;
        for (int i = 1; i < n; i++) {
            stringstream ss(lines[i]);
            for (int j = 0; j < m; j++) {
                ss >> grid[i][j];
            }
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    dp[0][0] = grid[0][0];
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
        parent[0][j] = {0, j - 1};
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
        parent[i][0] = {i - 1, 0};
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
                parent[i][j] = {i - 1, j};
            } else {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
                parent[i][j] = {i, j - 1};
            }
        }
    }

    vector<pair<int, int>> path;
    int cur_r = n - 1, cur_c = m - 1;
    while (cur_r != -1 && cur_c != -1) {
        path.push_back({cur_r, cur_c});
        auto p = parent[cur_r][cur_c];
        cur_r = p.first;
        cur_c = p.second;
    }
    for (int i = (int)path.size() - 1; i >= 0; i--) {
        cout << path[i].first << " " << path[i].second << endl;
    }

    return 0;
}
