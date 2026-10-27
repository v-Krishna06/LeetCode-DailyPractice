class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        string t = "";
        
        for(int i = 0;i<n;i++){
            t+='.';
        }
        ans.push_back(t);
        
        for(int i = 0;i<n-1;i++){
            t[i]='#';
        }
        for(int i = 1;i<m;i++){
            ans.push_back(t);
        }
        return ans;
    }
};