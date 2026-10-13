
class Solution {
public:
    bool f(string &word, unordered_set<string>& st,
           vector<int>& dp, int start) {
        int n = word.size();

        if (start == n) return true;
        if (dp[start] != -1) return dp[start];

        for (int i = start + 1; i <= n; i++) {
            string p = word.substr(start, i - start);

            if (st.find(p) != st.end() && f(word, st, dp, i)) {
                return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> res;

        for (string &word : words) {
            st.erase(word);

            vector<int> dp(word.size() + 1, -1);

            if (f(word, st, dp, 0)) {
                res.push_back(word);
            }

            st.insert(word);
        }

        return res;
    }
};
