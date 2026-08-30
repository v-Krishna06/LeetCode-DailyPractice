class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1 ;
        vector<int> a2;
        int n = nums.size();
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i = 2;i<n;i++){
            int arr1 = a1[a1.size()-1],arr2 = a2[a2.size()-1];
            if(arr1>arr2){
                a1.push_back(nums[i]);
            }
            else{
                a2.push_back(nums[i]);
            }
        }
        int i = 0;
        for(int j = 0;j<a1.size();j++){
            nums[i++]=a1[j];
        }
        for(int j = 0;j<a2.size();j++){
            nums[i++]=a2[j];
        }
        return nums;

    }
};