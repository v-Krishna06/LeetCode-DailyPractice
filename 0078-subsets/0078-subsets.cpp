class Solution {
public:
    vector<vector<int>> ans;
    void f(int i ,vector<int>& nums,vector<int>& curr){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        f(i+1,nums,curr);
        curr.pop_back();
        f(i+1,nums,curr);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> c;
        f(0,nums,c);
        return ans;

    }
};