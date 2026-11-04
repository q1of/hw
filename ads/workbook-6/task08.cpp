#include <iostream>
#include <vector>

using namespace std;

long long countPaths(int n) {
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n][n];
}

int main() {
    int n;
    if (!(cin >> n)) {
        n = 2;
    }
    cout << countPaths(n) << endl;
    return 0;
}
