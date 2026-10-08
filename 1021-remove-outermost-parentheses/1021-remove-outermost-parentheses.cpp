class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int c = 0;
        for(char ch : s){
            if(ch=='(' ){
                
                if(c>0){
                    ans.push_back('(');
                }
                c++;
            }
            else{
                c--;
                if(c>0){
                    ans.push_back(')');
                }
                
            }
        }
        return ans;
    }
};