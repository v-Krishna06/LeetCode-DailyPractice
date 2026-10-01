class Solution {
public:
    bool isPalindrome(int x) {
        long int a,b=0;
        long int v = x;
        while(x>0){
            a = x%10;
            b= (b*10) + a;
            x=x/10;
        }
        if(v == b){
            return true;
        }
        else{
            return false;
        }
    }
};