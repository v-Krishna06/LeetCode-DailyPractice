class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n==1){
            return{1};
        }
        vector<int>res = {1};
        while(res.size()<n){
            vector<int>temp;
            for(auto val:res){
                if((val*2) - 1<=n){
                    temp.push_back((val*2)-1);
                }
            }
            for(auto val:res){
                if(val*2<=n){
                    temp.push_back((val*2));
                }
            }
            res = temp;
        }
        return res;
    }
};