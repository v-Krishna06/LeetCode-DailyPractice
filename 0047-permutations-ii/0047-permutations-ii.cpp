class Solution {
public:
    vector<vector<int>>ans;
    vector<int> c;
    void f(vector<int>& nums ,vector<bool> &used ){
        if(c.size()==nums.size()){
            ans.push_back(c);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1]&& !used[i-1]) continue;
            used[i]=true;
            c.push_back(nums[i]);
            f(nums,used);
            c.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        vector<bool> used(n,false);
        f(nums,used);
        return ans;
    }
};