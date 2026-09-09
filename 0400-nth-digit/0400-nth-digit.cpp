class Solution {
public:
    int findNthDigit(int n) {
        long long dig = 1,count = 9,st = 1;
        while(n>count*dig){
            n-=dig*count;
            count*=10;
            dig++;
            st*=10;
        }
        long long num = st +(n-1)/dig;
        int idx = (n-1)%dig;
        string s = to_string(num);
        return s[idx]-'0';
    }
};