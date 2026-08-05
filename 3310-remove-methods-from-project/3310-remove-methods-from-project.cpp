class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        vector<bool> sus(n,false);
        for(auto &edge:inv){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        q.push(k);
        sus[k]=true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int ngbr : adj[cur]){
                indeg[ngbr]--;
                if(!sus[ngbr]){
                    q.push(ngbr);
                    sus[ngbr]=true;
                }
            }
        }
        vector<int> result;
        bool cannotRemove = false;
        for(int i = 0;i<n;i++){
            if(sus[i]&& indeg[i]>0){
                cannotRemove = true;
                break;
            }
            if(!sus[i]) {
                result.push_back(i);
            }
        }
        if(cannotRemove) {
            vector<int> vec(n); 
            for(int i = 0; i < n; i++) {
                vec[i] = i;
            }
            return vec;
        }
        return result;
    }
};