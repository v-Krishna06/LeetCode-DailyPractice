class Solution {
public:
    int n,m;
    int countServers(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<int> r(n),c(m);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1 &&(r[i]>1 || c[j]>1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};