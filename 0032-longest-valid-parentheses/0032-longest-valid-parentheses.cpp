class Solution {
public:
    int longestValidParentheses(string s) {
        int o = 0;
        int c = 0;
        int res = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]=='(') o++;
            else c++;
            if(o==c){
                res = max(res,o+c);
            }
            else if(c>o){
                o=0;
                c=0;
            }

        }
        o=0;
        c=0;
        for(int i = n-1;i>=0;i--){
            if(s[i]=='(') o++;
            else c++;
            if(o==c){
                res = max(res,o+c);
            }
            else if(o>c){
                o=0;
                c=0;
            }
        }
        return res;
    }
};