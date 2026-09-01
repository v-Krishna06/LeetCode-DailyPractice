class Solution {
public:
    set <vector<int>>s;
    void f(vector<int>&arr,int i,int tar,vector<vector<int>>&ans,vector<int>&comb){
        if(i==arr.size() || tar<0){
            return ;
        }
        if(tar==0){
            if(s.find(comb)==s.end()){
                ans.push_back(comb);
                s.insert(comb);
            }
            
            return;
        }
        comb.push_back(arr[i]);
        f(arr,i+1,tar-arr[i],ans,comb);
        f(arr,i,tar-arr[i],ans,comb);
        comb.pop_back();
        f(arr,i+1,tar,ans,comb);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        f(candidates,0,target,ans,comb);
        return ans;
    }
};