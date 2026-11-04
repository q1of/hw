#include <iostream>

using namespace std;

int main() {
    int n, m, w;
    cin >> n >> m >> w;
    int a[35][35] = {0};
    for (int k = 0; k < w; k++) {
        int r, c;
        cin >> r >> c;
        a[r - 1][c - 1] = -1;
    }
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == -1) {
                cout << "*";
            } else {
                int count = 0;
                for (int d = 0; d < 8; d++) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] == -1) {
                        count++;
                    }
                }
                cout << count;
            }
        }
        cout << endl;
    }
    return 0;
}
