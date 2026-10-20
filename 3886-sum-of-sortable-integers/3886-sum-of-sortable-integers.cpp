class Solution {
public:
    bool check(vector<int>& a) {
        int n = a.size();

        if (n == 1) return true;

        vector<int> v = a;
        for (int x : a) {
            v.push_back(x);
        }

        int c = 1;

        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i - 1] > v[i]) {
                c = 1;
            } else {
                c++;
            }

            if (c >= n) return true;
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> div;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                div.push_back(i);

                if (i * i != n) {
                    div.push_back(n / i);
                }
            }
        }

        int ans = 0;

        for (int k : div) {
            bool valid = true;
            int prevMax = -1;

            for (int i = 0; i < n; i += k) {
                vector<int> t;

                int mn = nums[i];
                int mx = nums[i];

                for (int j = i; j < i + k; j++) {
                    t.push_back(nums[j]);
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);
                }

                if (!check(t) || mn < prevMax) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};