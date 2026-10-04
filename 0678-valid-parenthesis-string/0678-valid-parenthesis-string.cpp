class Solution {
public:
    bool solve(int i, int c, string &s, vector<vector<int>>& dp) {

        if(c < 0)
            return false;

        if(i == s.size())
            return c == 0;

        if(dp[i][c] != -1)
            return dp[i][c];

        if(s[i] == '(') {
            return dp[i][c] = solve(i+1, c+1, s, dp);
        }

        if(s[i] == ')') {
            return dp[i][c] = solve(i+1, c-1, s, dp);
        }

        
        return dp[i][c] =
            solve(i+1, c+1, s, dp) ||
            solve(i+1, c, s, dp) ||
            solve(i+1, c-1, s, dp);
    }

    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(0, 0, s, dp);
    }
};