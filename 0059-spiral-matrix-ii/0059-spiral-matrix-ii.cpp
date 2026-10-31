class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0){
            return {};
        }
        vector<vector<int>>res(n,vector<int>(n,-1));;
        int t = 0,d = n-1,l = 0, r = n-1;
        int id = 0;
        int c = 1;
        while(t<=d &&l<=r){
            if(id == 0){
                for(int i = l;i<=r;i++){
                    res[t][i] = c++;
                }
                t++;
            }
            else if(id==1){
                for(int i = t;i<=d;i++){
                    res[i][r] = c++;
                }
                r--;
            }
            else if(id==2){
                for(int i = r;i>=l;i--){
                    res[d][i] = c++;
                }
                d--;
            }
            else if(id == 3){
                for(int i = d;i>=t;i--){
                    res[i][l] = c++;
                }
                l++;
            }
            id = (id+1)%n;
        }
        return res;

    }
};