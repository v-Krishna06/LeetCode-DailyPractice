class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int sum = 0;

        mp[0] = -1;

        // Store prefix sums and their indices
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }

        // Total sum is less than x -> impossible
        if (sum < x) {
            return -1;
        }

        int remainingSum = sum - x;
        int longestSubArray = INT_MIN;

        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int findSum = sum - remainingSum;

            if (mp.find(findSum) != mp.end()) {
                int idx = mp[findSum];

                int len = i - idx;

                longestSubArray = max(longestSubArray, len);
            }
        }

        if (longestSubArray == INT_MIN) {
            return -1;
        }

        return n - longestSubArray;
    }
};