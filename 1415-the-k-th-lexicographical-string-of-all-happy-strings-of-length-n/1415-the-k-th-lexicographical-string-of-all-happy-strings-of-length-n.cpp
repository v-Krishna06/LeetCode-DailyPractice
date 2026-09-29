class Solution {
public:
    void solve(int n , int i, string &temp,vector<string> & ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        if(temp[i-1]=='a'){
            temp.push_back('b');
            solve(n, i + 1, temp, ans);
            temp.pop_back();

            temp.push_back('c');
            solve(n, i + 1, temp, ans);
            temp.pop_back();

        }
        else if(temp[i-1]=='b'){
            temp.push_back('a');
            solve(n, i + 1, temp, ans);
            temp.pop_back();

            temp.push_back('c');
            solve(n, i + 1, temp, ans);
            temp.pop_back();
        }
        else{
            temp.push_back('a');
            solve(n, i + 1, temp, ans);
            temp.pop_back();

            temp.push_back('b');
            solve(n, i + 1, temp, ans);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        int t = 3 * (1 << (n - 1));
        if(k>t){
            return "";
        }
        vector<string> ans;
        string temp = "a";
        solve(n, 1, temp, ans);

        temp = "b";
        solve(n, 1, temp, ans);

        temp = "c";
        solve(n, 1, temp, ans);
        return ans[k-1];
    }
};