class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        
        while(st<=end){
            int mid = (end-st)/2 + st;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>target){
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return -1;
    }
};