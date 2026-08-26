class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        string ans = "";
        int cnt = 0;
        for(int j = 0;j<n;j++){
            if(s[j]=='1'){
                cnt++;
            }
            while(cnt==k){
                if(i<=k && s[i]=='0'){
                    i++;
                }
                string c = s.substr(i,j-i+1);

                if( ans == "" || ans.size()>c.size() || (c.size()==ans.size() && c<ans)){
                    ans = c;
                }
                if(s[i]=='1'){
                    cnt--;
                }
                i++;
            }
        }
        return ans;
    }
};