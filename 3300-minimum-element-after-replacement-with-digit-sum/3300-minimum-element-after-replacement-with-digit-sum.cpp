class Solution {
public:
    int s(int n){
        int ans = 0;
        while(n>0){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int mn=nums[0];
        for(int i=0;i<nums.size();i++){
            nums[i] = s(nums[i]);
            mn = min(mn,nums[i]);
        }
        return mn;
    }
};