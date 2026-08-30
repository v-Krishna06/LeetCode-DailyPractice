class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = -1,maxi = -1,mx = INT_MIN,mn = INT_MAX;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(mx<nums[i]){
                mx = nums[i];
                maxi = i;
            }
            if(mn>nums[i]){
                mn = nums[i];
                mini = i;
            }
        }
        int ans = 0;
        if(mini<maxi){
            ans = min({maxi+1,mini+1+(n-maxi),n-mini});
        }
        else if (mini>maxi){
            ans = min({mini+1,maxi+1+(n-mini),n-maxi});
        }
        else{
            ans = 1;
        }
        return ans;
    }
};