class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int s = nums[0];
        int n = nums.size();
        int l = nums[n-1];
        int i=0;
        while(s!=l){
            if(s==nums[i]){
                
                
                i++;
            }
            else{
                ans.push_back(s);
                
            }
            s++;
        }
        return ans;
    }
};