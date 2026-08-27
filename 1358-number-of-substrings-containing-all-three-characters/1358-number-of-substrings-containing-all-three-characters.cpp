class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3] = {0};
        int l = 0;
        int ans = 0;
        int n = s.size();
        for(int r = 0;r<n;r++){
            arr[s[r]-'a']++;
            while(arr[0]&&arr[1]&&arr[2]){
                ans+= n-r;
                arr[s[l]-'a']--;
                l++;
            }
        }return ans;
    }
};