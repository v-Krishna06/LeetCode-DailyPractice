class Solution {
public:
    int n,m;
    bool dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || c<0 || r>=n || c >=m){
            return false;
        }
        if(grid[r][c]==1){
            return true;
        }
        grid[r][c]=1; //imp
        bool l = dfs(grid,r,c-1);
        bool rg = dfs(grid,r,c+1);
        bool u = dfs(grid,r-1,c);
        bool d = dfs(grid,r+1,c);
        return (u && d && l && rg);
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for(int i = 0;i<n;i++ ){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)){
                    cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};