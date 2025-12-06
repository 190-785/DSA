class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long> abs_vals;
        for (int val : nums) {
            abs_vals.push_back(abs(static_cast<long long>(val)));
        }
        sort(abs_vals.begin(), abs_vals.end());
        long long res = 0;
        int right = 0;
        for (int i = 0; i < n; i++) {
            while (right < n && abs_vals[right] <= 2 * abs_vals[i]) {
                right++;
            }
            long long partners = (long long)right - i - 1;
            if (partners > 0) {
                res += partners;
            }
        }
        return res;
    }
};