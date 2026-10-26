class Solution {
public:
    int n,m;
    long long f(int i,int j,vector<vector<int>>& g,vector<vector<bool>> &v){
        if(i>=n || j>=m || i<0 || j<0 || g[i][j]==0 || v[i][j]){
            return 0;
        }
        v[i][j]=true;
        long long sum = g[i][j];

        sum += f(i, j + 1, g, v);
        sum += f(i + 1, j, g, v);
        sum += f(i - 1, j, g, v);
        sum += f(i, j - 1, g, v);

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> v(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]!=0 && !v[i][j]){
                    long long sum = f(i,j,grid,v);
                    if(sum%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};