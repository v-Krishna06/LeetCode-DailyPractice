class Solution {
public:
    int f(int i , int j, int n,int m ,vector<vector<int>>& dp,vector<vector<int>>& v){
        if(i==n || j==m){
            return 0;
        }
        if(v[i][j]){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]= f(i+1,j,n,m,dp,v)+f(i,j+1,n,m,dp,v);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,n,m,dp,v);
    }
};