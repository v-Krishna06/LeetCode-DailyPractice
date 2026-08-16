class Solution {
public:
    int magicalString(int n) {
        if(n<=3){
            return 1;
        }
        queue<int>q;
        int count = 1;
        int curr = 1;
        q.push(2);
        for(int i = 2;i<n;i++){
            int currcnt = q.front();
            q.pop();
            for(int j = 0;j<currcnt;j++){
                q.push(curr);
                if(currcnt==1){
                    count++;
                }
                
            }
            curr = (curr == 1 ? 2 : 1);
            
        }
        return count;

    }
};