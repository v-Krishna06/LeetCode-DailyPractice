class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, h = m*n - 1;
        while(l<=h){
            int mid = l+(h-l)/2;
            int r = mid/m, c = mid%m;
            if(mat[r][c]==t){
                return true;
            }
            else if(mat[r][c]<t){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return false;
    }
};