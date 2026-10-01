class Solution {
public:
    int pivotInteger(int n) {
        int ts = n*(n+1)/2;
        for(int i = 1;i<=n;i++){
            int f = i*(i+1)/2;
            int s = ts - f + i;
            if(f==s){
                return i;
            }
        }
        return -1;
    }
};