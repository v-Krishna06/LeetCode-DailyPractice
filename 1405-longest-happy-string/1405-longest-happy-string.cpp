class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string res = "";
        while(!pq.empty()){
            int ccount = pq.top().first;
            int cchar = pq.top().second;
            pq.pop();

            if(res.size()>=2 && res[res.size()-1]==cchar && res[res.size()-2]==cchar){
                if(pq.empty()){
                    break;
                    }
                int ncount = pq.top().first;
                int nchar = pq.top().second;
                pq.pop();
                res.push_back(nchar);
                ncount--;
                if(ncount>0){
                    pq.push({ncount,nchar}); 
                }
            }
            else{
                ccount--;
                res.push_back(cchar);
            }
            if(ccount>0){
                pq.push({ccount,cchar});
            }
        }
        return res;
    }
};