class Solution {
public:
    int minInsertions(string s) {
        int c = 0;
        int ans = 0;
        int i = 0;
        while(i<s.size()){
            if(s[i]=='('){
                c++;
                i++;
            }
            else{
                if(c>0){
                    c--;
                }
                else{
                    ans++;
                }
                if(i+1<s.size() && s[i+1]==')'){
                    i+=2;
                }
                else{
                    ans++;
                    i++;
                }
            }
        }
        
        return ans + (c*2);
    }
};