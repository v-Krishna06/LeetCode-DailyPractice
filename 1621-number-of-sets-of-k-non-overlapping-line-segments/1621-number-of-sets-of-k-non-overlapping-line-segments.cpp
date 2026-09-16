class Solution {
public:
    int m = 1e9+7;
    int dp[1001][1001];
    int solve(int n,int k,int i){
        if(k==0){
            return 1;
        }
        if(i>=n){
            return 0;
        }
        if(dp[k][i]!=-1) return dp[k][i];
        int t = 0;
        for(int j = i+1;j<n;j++){
            t= (t+solve(n,k-1,j))%m;
        }
        int s = solve(n,k,i+1);
        return dp[k][i] = (s+t)%m;
    }
    int numberOfSets(int n, int k) {
        if(k>n-1) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(n,k,0)%m;

    }
};