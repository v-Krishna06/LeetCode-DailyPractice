class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = sqrt(c);
        while(a<=b){
            long temp = a*a + b*b;
            if(temp == c){
                return true;
            }
            if(temp<c){
                a++;
            }
            else if(temp>c){
                b--;
            }

        }
        return false;
    }
};