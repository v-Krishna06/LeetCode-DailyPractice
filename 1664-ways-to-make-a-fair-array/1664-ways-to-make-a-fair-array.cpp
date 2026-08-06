class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int et = 0,ot = 0;
        for(int i = 0;i<n;i++){
            if(i%2==0){
                et+=nums[i];
            }
            else{
                ot+=nums[i];
            }
        }
        int ep=0,op=0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int ne,no;
            if(i%2==0){
                ne = ep + (ot-op);
                no = op + (et- ep-nums[i]);
            }
            else{
                ne = ep + (ot - op - nums[i]);
                no = op +(et - ep);

            }
            if(ne == no){
                ans++;
            }
            if(i%2==0){
                ep+=nums[i];
            }
            else{
                op+=nums[i];
            }
        }
        return ans;
    }
};