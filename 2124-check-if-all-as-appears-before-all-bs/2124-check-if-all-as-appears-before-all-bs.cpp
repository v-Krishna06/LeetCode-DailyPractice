class Solution {
public:
    bool checkString(string s) {
        int ai = -1,bi = -1;
        for(int i =0;i<s.size();i++){
            if(s[i]=='b'){
                bi = i;
                break;
            }
        }
        for(int i =s.size();i>=0;i--){
            if(s[i]=='a'){
                ai = i;
                break ;
            }
        }
        if(ai == -1 || bi == -1){
            return true;
        }
        return ai<bi;
    }
};