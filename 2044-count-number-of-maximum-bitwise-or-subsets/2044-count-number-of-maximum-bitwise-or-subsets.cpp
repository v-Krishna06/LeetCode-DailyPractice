class Solution {
public:
    int ans = 0,t = 0;
    void f(int i,int c,vector<int>& nums){
        if(i==nums.size()){
            if(c==t){
                ans++;
            }
            return;
        }
        f(i+1,c|nums[i],nums);
        f(i+1,c,nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for(int x:nums){
            t|=x;
        }
        f(0,0,nums);
        return ans;
    }
};