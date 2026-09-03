class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool e = false, o = false;
        int sm = INT_MAX;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                e = true;
            }
            else{
                o = true;
            }
            if(sm>nums1[i]){
                sm = nums1[i];
            }
        }
        if(o && e){
            if(sm%2==0){
                return false;
            }
            return true;
        }
        return true;
    }
};