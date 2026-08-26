class Solution {
public:
    string convert(string s, int n) {
        if(n==1){
            return s;
        }
        string res = "";
        for(int r = 0;r<n;r++){
            int inc = 2*(n-1);
            for(int i = r;i<s.size();i+=inc){
                res+=s[i];
                if(r>0 && r<n-1 && i+inc-2*r<s.size()){
                    res+= s[i+inc-2*r];
                }
            }
        }
        return res;
    }
};