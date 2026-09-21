class Solution {
public:
    int s,n,m;
    bool f(vector<vector<char>>& board, string word,int p,int i,int j,vector<vector<bool>>& v){
        if(i>=n || i<0 || j>=m || j<0){
            return false;
        }
        if(v[i][j])
            return false;
        if(board[i][j] != word[p]){
            return false;
        }
        if(p==word.size()-1){
            return true;
        }
        v[i][j]=true;
        bool ans =
            f(board, word, p + 1, i + 1, j, v) ||
            f(board, word, p + 1, i - 1, j, v) ||
            f(board, word, p + 1, i, j + 1, v) ||
            f(board, word, p + 1, i, j - 1, v);
        v[i][j] = false;
        return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        s = word.size();
        n = board.size();
        m = board[0].size();
        
        int p = 0;
        vector<vector<bool>> v(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(f(board,word,p,i,j,v)){
                    return true;
                }
            }
        }
        return false;

    }
};