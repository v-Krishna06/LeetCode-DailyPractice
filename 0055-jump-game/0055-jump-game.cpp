class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mi = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mi<i){
                return false;
            }
            mi= max(mi,i+nums[i]);
        }
        return true;
    }
};