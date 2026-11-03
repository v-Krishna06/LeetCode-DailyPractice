class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = 0;
        for(int i =0;i<nums.size()-1;i++){
            s+=(nums[nums.size()-1] - nums[i]);
        }
        return s;
    }
};