class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int res = accumulate(nums.begin(), nums.end(), 0);
        int rem = res % 3;
        if (rem == 0)
            return res;

        const int INF = 1e9;
        int min1[2] = {INF, INF};
        int min2[2] = {INF, INF};

        for (int x : nums) {
            int r = x % 3;
            if (r == 1) {
                if (x < min1[0]) {
                    min1[1] = min1[0];
                    min1[0] = x;
                } else if (x < min1[1]) {
                    min1[1] = x;
                }
            } else if (r == 2) {
                if (x < min2[0]) {
                    min2[1] = min2[0];
                    min2[0] = x;
                } else if (x < min2[1]) {
                    min2[1] = x;
                }
            }
        }

        int remove = INF;
        if (rem == 1) {
            if (min1[0] != INF)
                remove = min(remove, min1[0]);
            if (min2[1] != INF)
                remove = min(remove, min2[0] + min2[1]);
        } else {
            if (min2[0] != INF)
                remove = min(remove, min2[0]);
            if (min1[1] != INF)
                remove = min(remove, min1[0] + min1[1]);
        }

        if (remove == INF)
            return 0;
        return res - remove;
    }
};
