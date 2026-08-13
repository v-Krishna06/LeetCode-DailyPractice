class Solution {
public:
    int h(int st,int end,vector<int>& nums){
        if(st>=end){
            return 0;
        }
        int mid = (end-st)/2 + st;
        int l = h(st,mid,nums);
        int r = h(mid+1,end,nums);
        int i = st,j = mid+1;
        int ans = l+r;
        vector<int>temp;
        while(i<=mid){
            while(j <= end && (long long)nums[i]>2LL*nums[j]){
                j++;
            }
            ans+=j-mid-1;
            i++;
        }
        i = st;
        j=mid+1;
        while(i<=mid && j<=end){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }
        i=0;
        for(int k = st;k<=end;k++){
            nums[k] = temp[i];
            i++;
        }
        return ans;

    }
    int reversePairs(vector<int>& nums) {
        return h(0,nums.size()-1,nums);

    }
};