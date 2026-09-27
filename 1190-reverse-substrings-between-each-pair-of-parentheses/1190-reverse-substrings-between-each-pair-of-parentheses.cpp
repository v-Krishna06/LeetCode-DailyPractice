class Solution {
public:
    string reverseParentheses(string s) {
        stack <string> st;
        string temp = "";
        for(char c : s){
            if(c=='('){
                st.push(temp);
                temp = "";
            }
            else if (c==')'){
                reverse(temp.begin(), temp.end());
                string p = st.top();
                st.pop();
                temp = p + temp;
            }
            else{
                temp = temp + c;
            }
        }
        return temp;

        
    }
};