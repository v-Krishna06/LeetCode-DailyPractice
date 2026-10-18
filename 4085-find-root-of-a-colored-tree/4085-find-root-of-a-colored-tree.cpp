class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int> in(n,0),out(n,0);
        
        auto nC = [](char c){
            if(c=='R') return 'B';
            if(c=='B') return 'W';
            return 'R';
        };
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            
            if(nC(colors[u])==colors[v]){
                out[u]++;
                in[v]++;
            }
            else if(nC(colors[v])==colors[u]){
                out[v]++;
                in[u]++;
            }
            else {
                return -1;
            }
        }
        int r = -1;
        for(int i = 0;i<n;i++){
            if(in[i]==0){
                if(r!=-1) return -1;
                r = i;
            }
            if(out[i]>2)return -1;
        }
        return r;
    }
};