class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int countOne = 0;
        for (int x : nums) if (x == 1) ++countOne;
        if (countOne > 0) return n - countOne;

        int totalGcd = nums[0];
        for (int i = 1; i < n; ++i) totalGcd = std::gcd(totalGcd, nums[i]);
        if (totalGcd != 1) return -1;

        int bestLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = std::gcd(g, nums[j]);
                if (g == 1) {
                    bestLen = min(bestLen, j - i + 1);
                    break;
                }
            }
        }
        return (n - 1) + (bestLen - 1);
    }
};
