class Solution {
public:
    bool h(int n,int t){
        int p = 1;
        while(n>0){
            int d = n%10;
            p*=d;
            n/=10;

        }
        return (p%t == 0);
    }
    int smallestNumber(int n, int t) {
        
        while(true){
            if(h(n,t)){
                break;
            }
            else{
                n++;
            }
        }
        return n;
    }
};