class Solution {
public:
    int magicalString(int n) {
        if(n <= 3)
            return 1;

        vector<int> s = {1, 2, 2};

        int i = 2;
        int num = 1;
        int count = 1;

        while(s.size() < n) {
            int freq = s[i];

            for(int j = 0; j < freq && s.size() < n; j++) {
                s.push_back(num);

                if(num == 1)
                    count++;
            }

            num = 3 - num;
            i++;
        }

        return count;
    }
};