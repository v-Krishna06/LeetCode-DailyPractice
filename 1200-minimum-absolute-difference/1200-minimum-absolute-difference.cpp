class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans = INT_MAX;
        int n = arr.size();
        for(int i = 1;i<n;i++){
            ans = min(ans,arr[i]-arr[i-1]);
        }
        vector<vector<int>> v;
        for(int i = 1;i<n;i++){
            if(ans == (arr[i]-arr[i-1]) ){
                v.push_back({arr[i-1],arr[i]});
            }
        }
        return v;

    }
};