class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set <int> s;
        for(int x:nums){
            s.insert(x);
        } 
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