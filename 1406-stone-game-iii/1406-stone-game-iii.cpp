class Solution {
public:
    int helper(int i ,int n,vector<int>&nums,vector<int> &a){
        if(i>=n){
            return 0;
        }   
        
        if(a[i]!=-1){
            return a[i];
        } 
        else{
            int t1 = nums[i] - helper(i+1,n,nums,a);
            if(i+1<n) {
                t1 = max(t1,nums[i]+nums[i+1]-helper(i+2,n,nums,a));
            }
            if(i+2<n) {
                t1 = max(t1,nums[i]+nums[i+1]+nums[i+2]-helper(i+3,n,nums,a));
            }

            
            return a[i]=t1;
        }
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>a(n,-1);
        int diff = helper(0,n,stoneValue,a);
        if(diff<0){
            return "Bob";
        }
        else if (diff>0){
            return "Alice";
        }
        return "Tie";
    }
};