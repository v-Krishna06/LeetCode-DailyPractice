class Solution {
public:
    int n, m;
    int mod = 1e9 + 7;

    int f(int i, int j, int prev,
          vector<vector<vector<int>>>& dp,
          vector<vector<int>>& grid) {

        if (i >= n || j >= m)
            return 0;

        if (i == n - 1 && j == m - 1)
            return 1;

        if (dp[i][j][prev] != -1)
            return dp[i][j][prev];

        long long ans = 0;

        if (grid[i][j] == 1) {

            if (prev != 0) {
                ans = (ans + f(i + 1, j, 0, dp, grid)) % mod;
            }

            if (prev != 1) {
                ans = (ans + f(i, j + 1, 1, dp, grid)) % mod;
            }

        }
        else {
            ans = (ans + f(i + 1, j, 0, dp, grid)) % mod;
            ans = (ans + f(i, j + 1, 1, dp, grid)) % mod;
        }

        return dp[i][j][prev] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, -1))
        );

        return f(0, 0, 2, dp, grid);
    }
};