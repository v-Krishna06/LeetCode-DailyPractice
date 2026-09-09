class Solution {
public:
    int countDigits(int num) {
        vector<int>p(10,0);
        int n = num;
        while(n>0){
            int d = n%10;
            p[d]++;
            n/=10;
        }
        int ans = 0;
        for(int i =1;i<10;i++){
            if(p[i] && num%i==0){
                ans+=p[i];
            }
        }
        return ans;
    }
};