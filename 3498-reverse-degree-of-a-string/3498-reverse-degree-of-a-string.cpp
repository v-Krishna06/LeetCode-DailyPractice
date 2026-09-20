class Solution {
public:
    int reverseDegree(string s) {
        vector<int> f(26);
        int val = 26;
        for(int i = 0;i<26;i++){
            f[i]=val;
            val--;
        }
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            ans+=((i+1)*f[s[i]-'a']);
        }
        return ans;
    }
};