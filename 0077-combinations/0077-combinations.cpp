class Solution {
public:
    void solve(int i , int n,int k ,vector<vector<int>>&ans,vector<int>&temp){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(i==n+1){
            return;
        }
        temp.push_back(i);
        solve(i+1,n,k,ans,temp);
        temp.pop_back();
        solve(i+1,n,k,ans,temp);
        return;


    }
    vector<vector<int>> combine(int n, int k) {
        int i = 1;
        vector<vector<int>> ans;
        vector<int>temp;
        solve(i,n,k,ans,temp);
        return ans;
    }
};