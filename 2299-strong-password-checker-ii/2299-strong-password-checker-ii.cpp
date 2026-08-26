class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool len = false,low = false,upp=false,dig = false,nrep = true,spchar = false;
        if(password.size()>=8){
            len = true;
        }
        char prev = '_';
        for(char ch:password){
            if(islower(ch)){
                low = true;
            }
            if(isupper(ch)){
                upp = true;
            }
            if(isdigit(ch)){
                dig = true;
            }
            if(prev == ch){
                nrep = false;
            }
            prev = ch;
            if(ch=='!' || ch=='@' || ch=='#' || ch=='$' ||ch=='%' || ch=='^' || ch=='&' || ch=='*' || ch=='(' ||ch==')' ||ch=='-' ||ch=='+'){
                spchar = true;
            }

        }
        return len && low && upp && dig && nrep && spchar;
        
    }
};