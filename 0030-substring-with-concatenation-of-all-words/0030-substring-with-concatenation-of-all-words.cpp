class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> freq;

        for (string& word : words) {
            freq[word]++;
        }

        int len = s.size();
        int n = words.size();
        int wordSize = words[0].size();
        int windowSize = n * wordSize;

        vector<int> ans;

        for (int offset = 0; offset < wordSize; offset++) {
            unordered_map<string, int> curr;
            int left = offset, count = 0;

            for (int right = offset; right + wordSize <= len; right += wordSize) {
                string word = s.substr(right, wordSize);

                if (freq.find(word) == freq.end()) {
                    curr.clear();
                    count = 0;
                    left = right + wordSize;
                    continue;
                }

                curr[word]++;
                count++;

                while (curr[word] > freq[word]) {
                    string leftWord = s.substr(left, wordSize);
                    curr[leftWord]--;
                    count--;
                    left += wordSize;
                }

                if (count == n) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, wordSize);
                    curr[leftWord]--;
                    count--;
                    left += wordSize;
                }
            }
        }

        return ans;
    }
};