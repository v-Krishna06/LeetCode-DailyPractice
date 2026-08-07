class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        int n = inter.size();
        int st = inter[0][0];
        int end = inter[0][1];
        vector<vector<int>> ans;
        for(int i = 1;i<n;i++){
            if(end<inter[i][0]){
            ans.push_back({st,end});
            st = inter[i][0];
            end = inter[i][1];
            }
            else{
                end = max(end,inter[i][1]);
            }
            

            
            
        }
        ans.push_back({st,end});
        return ans;
    }
};