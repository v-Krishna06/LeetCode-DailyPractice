class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int prev = nums[0];
        int sum=nums[0];
        
        for(int x:nums){
            s.insert(x);
        }
        for(int i = 1;i<n;i++){
            
            if(prev+1 == nums[i]){
                sum+=nums[i];
                prev++;
            }
            else{
                break;
            }
        }
        while(s.find(sum) != s.end()) {
            sum++;
        }
        return sum;
    }
};