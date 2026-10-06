class Solution {
public:
    int minAddToMakeValid(string s) {
        int c = 0;
        int ans=0;
        for(char ch : s){
            if(ch == '('){
                c++;
            }
            else{
                
                if(c<=0){
                    ans++;
                }
                else{
                    c--;
                }
            }
        }
        return ans + c;
    }
};