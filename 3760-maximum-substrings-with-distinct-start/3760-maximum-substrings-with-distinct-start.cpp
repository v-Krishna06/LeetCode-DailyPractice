class Solution {
public:
    int maxDistinct(string s) {
        vector<bool>freq(26,false);
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(!freq[s[i]-'a']){
                freq[s[i]-'a'] = true;
                ans++;
            }
        }
        return ans;

    }
};