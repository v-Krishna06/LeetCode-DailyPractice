class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int i=1;
        while(true){
            int ans = i*k;
            if(s.find(ans)==s.end()){
                return ans;
            }
            i++;
        }
        return 0;
    }
};