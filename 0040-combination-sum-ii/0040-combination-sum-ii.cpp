class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,vector<int>& c,vector<int>temp,int t){
        if(t<0){
            return;
        }
        if(t==0){
            ans.push_back(temp);
            return;
        }
        for(int j = i;j<c.size();j++){
            if(j>i && c[j]==c[j-1]){
                continue;
            }
            temp.push_back(c[j]);
            solve(j+1,c,temp,t-c[j]);
            temp.pop_back();
            
        }
        


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int t) {
        
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,temp,t);
        return ans;
    }
};