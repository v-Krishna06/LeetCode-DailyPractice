class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[0]+nums[1]+nums[2];
        for(int i = 0;i<n-2;i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
            if(abs(t-sum)<abs(t-ans)){
                ans = sum;
            }
            if(sum<t){
                l++;
            }
            else if (sum>t){
                r--;
            }
            else{
                return sum;
            }
            }
        }
        return ans;
    }
};