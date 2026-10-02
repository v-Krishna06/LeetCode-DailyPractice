class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        f(r,0,0,n,"");
        return r;
    }
    void f(vector<string>&r,int o,int c,int n,string curr){
        if(n==c && o==n){
            r.push_back(curr);
            return;
        }
        if(o<n){
            f(r,o+1,c,n,curr+"(");

        }
        if(c<o){
            f(r,o,c+1,n,curr+")");
        }
    }
};