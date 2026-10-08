class Solution {
public:
    int myAtoi(string s) {
        
        int i =0;
        long long a = 0;
        int n = s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        bool neg = false;
        if(i < n && s[i] == '-'){
            i++;
            neg = true;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<n && isdigit(s[i])){
            int d=s[i]-'0';
            if(a>(INT_MAX-d)/10){
                return neg? INT_MIN : INT_MAX;
            }
            a = a*10 + d;
            i++;
        }
        if(neg){
            a*=-1;
        }
        return a;
    }
};