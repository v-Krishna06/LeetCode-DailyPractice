class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        map<int,vector<int>> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>res;
        for(int q : queries){
            int ele = nums[q];
            vector<int> &vec = mp[ele];
            int sz = vec.size();
            if(sz==1){
                res.push_back(-1);
                continue;
            }
            int pos = lower_bound(begin(vec),end(vec),q)-begin(vec);
            int re = INT_MAX;
            
            int r = vec[(pos+1)%sz];
            int d = abs(q-r);
            int cd = abs(n-d);
            re = min({re,d,cd});

            int l = vec[(pos-1+sz)%sz];
            d = abs(q-l);
            cd = abs(n-d);
            re = min({re,d,cd});
            res.push_back(re);
            
        }
        return res;
    }
};