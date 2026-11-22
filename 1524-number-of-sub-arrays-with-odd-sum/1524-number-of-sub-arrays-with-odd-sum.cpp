class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int e = 1;
        int o = 0;
        int s = 0;
        int ans = 0;
        for(int x:arr){
            s+=x;
            if(s%2==0){
                ans = (ans+o)%mod;
                e++;
            }
            else{
                ans = (ans+e)%mod;
                o++;
            }
        }
        return ans;
    }
};