class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        int matched = 0;
        int i = n-1,j=m-1;
        vector<int> matching(n,0);
        while(i>=0){
            if(j>=0 && w1[i]==w2[j]){
                matched++;
                j--;
            }
            matching[i]=matched;
            i--;
        }
        vector<int>seq;
        i=0;
        j=0;
        bool pow = true;
        while(i<n && j<m){
            if(w1[i]==w2[j]){
                seq.push_back(i);
                j++;
            }
            else if(pow && i+1<n && matching[i+1]>=m-j-1){
                seq.push_back(i);
                j++;
                pow = false;
            }
            i++;
        }
        return j==m ? seq : vector<int> ();
    }
};