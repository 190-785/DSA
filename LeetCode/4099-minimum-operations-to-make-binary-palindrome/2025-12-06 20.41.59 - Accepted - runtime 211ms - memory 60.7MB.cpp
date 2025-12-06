class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> dp;
        const int LIMIT = 10000;
        vector<int> ans(n, 0);
        // Using log2 to find the max bits for a number
        int maxBits = (int)log2(LIMIT) + 1;
        // To not get banned
        // First I precompute every possible palindrome number [ in bits way ]
        //  Since the limit is not much
        // After creating the dp array or here sets since duplicates can happen
        for (int i = 1; i <= maxBits; i++) {
            int palHalf = (i + 1) / 2;
            int start = 1 << (palHalf - 1);
            int end = (1 << palHalf) - 1;
            for (int j = start; j <= end; j++) {
                int x = j;
                int reve = j >> (i % 2);
                while (reve) {
                    x = (x << 1) | (reve & 1);
                    reve >>= 1;
                }
                if (x > LIMIT)
                    continue;
                dp.insert(x);
            }
        }
        int i = 0;
        // Now after doing all this we just check for lower bound along with
        // prev of that So we can obtain the min diff between the next and prev
        // num That diff is our answer
        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            int minDiff = INT_MAX;
            if (it != dp.end())
                minDiff = min(minDiff, abs((*it) - num));
            if (it != dp.begin()) {
                it--;
                minDiff = min(minDiff, abs((*it) - num));
            }
            ans[i] = minDiff;
            i++;
        }
        return ans;
    }
};