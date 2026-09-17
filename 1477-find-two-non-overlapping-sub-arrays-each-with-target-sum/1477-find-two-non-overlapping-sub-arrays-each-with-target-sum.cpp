class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int t) {
        int n = arr.size(), i = 0,j= 0;
        int currSum = 0;
        int res = INT_MAX;
        int mnlen = INT_MAX;
        vector<int>lenIdx(n,INT_MAX);
        while(j<n){
            currSum+=arr[j];
            while(i<j && currSum>t){
                currSum-=arr[i++]; 
            }
            if(currSum==t){
                int l = j-i+1;
                if(i>0 && lenIdx[i-1]!=INT_MAX){
                    res = min(res,l + lenIdx[i-1]);
                }
                mnlen = min(mnlen,l);
                
            }
            lenIdx[j++]=mnlen;
        }
        return res == INT_MAX?-1:res;
    }
};