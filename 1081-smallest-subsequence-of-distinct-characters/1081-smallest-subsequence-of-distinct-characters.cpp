class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string res = "";
        vector<bool> taken(26,false);
        vector<int> lidx(26);
        for(int i = 0;i<n;i++){
            lidx[s[i]-'a'] = i;
        }
        for(int i = 0;i<n;i++){
            int idx = s[i]-'a';
            if(taken[idx]) continue;
            while(res.size()>0 && res.back()>s[i] && lidx[res.back()-'a']>i){
                taken[res.back()-'a'] = false;
                res.pop_back();
                
            }
            res.push_back(s[i]);
            taken[idx] = true;
        }
        return res;
    }
};