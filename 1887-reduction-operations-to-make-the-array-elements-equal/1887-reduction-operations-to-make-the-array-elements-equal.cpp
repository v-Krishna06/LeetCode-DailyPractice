class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 1;
        
        int ans = 0;
        if(n>1){
            for(int i = n-1;i>0;i--){
            if(nums[i-1]!=nums[i]){
                ans+= cnt;
            }
            cnt++;
            }
        }
        
        return ans;
    }
};