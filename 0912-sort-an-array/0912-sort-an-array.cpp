class Solution {
public:
    void fn(vector<int> &nums,int l, int r){
        if(l>=r){
            return;
        }
        int mid = (r-l)/2 + l;
        fn(nums,l,mid);
        fn(nums,mid+1,r);
        vector<int> temp;
        int i = l,j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=r){
            temp.push_back(nums[j++]);
        }
        for(int k = 0;k<temp.size();k++){
            nums[l+k] = temp[k];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        fn(nums,0,nums.size()-1);
        return nums;
    }
};