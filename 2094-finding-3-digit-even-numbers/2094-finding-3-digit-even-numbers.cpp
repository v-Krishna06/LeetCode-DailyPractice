class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& d) {
        int n = d.size();
        unordered_set<int>st;
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k = 0;k<n;k++){
                    if(i==j || j==k ||i==k) continue;
                    int num = d[i]*100+d[j]*10+d[k];
                    if(num>=100 && num%2==0){
                        st.insert(num);
                    }
                }
            }
        }
        vector<int> res(st.begin(),st.end());
        sort(res.begin(),res.end());
        return res;
    }
};