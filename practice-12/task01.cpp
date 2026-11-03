#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cctype>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        string row = "";
        while (row.length() < (size_t)m) {
            string token;
            if (!(cin >> token)) break;
            for (char c : token) {
                if (c == '0' || c == '1' || c == 'P' || c == 'p' || c == 'E' || c == 'e' || c == 'S' || c == 's' || c == 'D' || c == 'd') {
                    row += toupper(c);
                }
            }
        }
        grid[i] = row;
    }

    int start_r = 0, start_c = 0;
    bool found_start = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S' || grid[i][j] == 'D') {
                start_r = i;
                start_c = j;
                found_start = true;
                break;
            }
        }
        if (found_start) break;
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    int p_count = 0;
    bool can_reach_e = false;

    if (grid[start_r][start_c] != '1') {
        visited[start_r][start_c] = true;
        if (grid[start_r][start_c] == 'P') p_count++;
        if (grid[start_r][start_c] == 'E') can_reach_e = true;
        q.push({start_r, start_c});
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] != '1') {
                visited[nr][nc] = true;
                if (grid[nr][nc] == 'P') p_count++;
                if (grid[nr][nc] == 'E') can_reach_e = true;
                q.push({nr, nc});
            }
        }
    }

    if (can_reach_e) {
        cout << p_count << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
