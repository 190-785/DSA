class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxE = INT_MIN;
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        for (int i = 0; i < n; i++) {
            if (prefix == 0) {
                prefix = 1;
            }
            if (suffix == 0) {
                suffix = 1;
            }
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            maxE = max(maxE, max(suffix, prefix));
        }
        return maxE;
    }
};