class Solution {
public:
    int dig(int n){
        int ans = 0;
        while(n>0){
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            if(dig(nums[i])==i){
                return i;
            }
        }
        return -1;
    }
};