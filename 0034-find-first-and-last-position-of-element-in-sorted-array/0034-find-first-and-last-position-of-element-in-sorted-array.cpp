class Solution {
public:
    int hl(vector<int>& nums, int target,int n){
       int l = 0;
       int r = n-1;
       int lm = -1;
       while(l<=r){
        int m = l+(r-l)/2;
        if(nums[m]==target){
            lm = m;
            r = m-1;
        }
        else if(nums[m]<target){
            l=m+1;
        }
        else{
            r = m-1;
        }
        
       }
       return lm;
    }
    int hr(vector<int>& nums, int target,int n){
       int l = 0;
       int r = n-1;
       int rm = -1;
       while(l<=r){
        int m = l+(r-l)/2;
        if(nums[m]==target){
            rm = m;
            l = m+1;
        }
        else if(nums[m]<target){
            l=m+1;
        }
        else{
            r = m-1;
        }
        
       }
       return rm;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = hl(nums,target,n);
        int r = hr(nums,target,n);
        return {l,r};
    }
};