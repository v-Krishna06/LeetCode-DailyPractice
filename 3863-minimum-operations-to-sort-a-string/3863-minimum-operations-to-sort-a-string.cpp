class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(begin(s),end(s))){
            return 0;
        }
        if(n==2){
            return -1;
        }
        char mx_char = *max_element(begin(s),end(s));
        char mn_char = *min_element(begin(s),end(s));
        if(mn_char==s[0]||mx_char==s[n-1]){
            return 1;
        }
        char max_char = *max_element(begin(s)+1,end(s)-1);
        char min_char = *min_element(begin(s)+1,end(s)-1);
        if(max_char<s[0] && min_char>s[n-1]){
            return 3;
        }
        return 2;
        

    }
};