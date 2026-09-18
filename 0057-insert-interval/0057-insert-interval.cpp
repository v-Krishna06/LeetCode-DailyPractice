class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i++]);
        }
        int st = newInterval[0];
        int end = newInterval[1];
        while(i<n && intervals[i][0] <= end){
            st = min(st, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        res.push_back({st,end});
        while(i<n){
            res.push_back(intervals[i++]);
        }
        return res;

    }
};