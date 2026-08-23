class Solution {
public:
    bool sumGame(string num) {
       int n = num.size();
       int s1=0,q1=0,s2=0,q2=0;
       for(int i = 0;i<n;i++){
        if(i<n/2){
           if(num[i]=='?'){
            q1+=1;
           }
           else{
            s1+=(num[i]-'0');
           }
        }
        else{
            if(num[i]=='?'){
            q2++;
           }
           else{
            s2+=(num[i]-'0');
           }
        }

       }
       return ((q1 + q2) % 2 == 1 ||
                s1 - s2 != (q2 - q1) / 2 * 9);
    }
};