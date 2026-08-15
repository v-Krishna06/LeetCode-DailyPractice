class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        bool allz = true;
        for(int i = 0;i<nums.size();i++){
            ans=ans^nums[i];
            if(nums[i]!=0){
                allz = false;
            }
        }
        if(allz){
            return 0;
        }
        return ans==0? nums.size()-1 :nums.size();
    }
};