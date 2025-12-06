class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(32, 0);
        int orValue = 0;
        int l = 0;
        int minLen = n + 1;

        for (int r = 0; r < n; ++r) {
            for (int b = 0; b < 32; ++b) {
                if (nums[r] & (1 << b)) {
                    if (cnt[b]++ == 0) {
                        orValue |= (1 << b);
                    }
                }
            }

            while (l <= r && orValue >= k) {
                minLen = min(minLen, r - l + 1);

                for (int b = 0; b < 32; ++b) {
                    if (nums[l] & (1 << b)) {
                        if (--cnt[b] == 0) {
                            orValue &= ~(1 << b);
                        }
                    }
                }
                ++l;
            }
        }

        return (minLen == n + 1 ? -1 : minLen);
    }
};
