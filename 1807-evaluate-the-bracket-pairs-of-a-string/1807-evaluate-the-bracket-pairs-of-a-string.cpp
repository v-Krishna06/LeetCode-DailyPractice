class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string,string> mp;
        for(auto &vec : knowledge){
            mp[vec[0]]=vec[1];
        }
        int i = 0;
        string res="";
        while(i<n){
            if(s[i]=='('){
                int j = s.find(')',i+1);
                string temp = s.substr(i+1,j-i-1);
                res += mp.count(temp) ? mp[temp] :"?";
                i=j+1;
            }
            else{
                res.push_back(s[i++]);
            }
        }
        return res;
    }
};