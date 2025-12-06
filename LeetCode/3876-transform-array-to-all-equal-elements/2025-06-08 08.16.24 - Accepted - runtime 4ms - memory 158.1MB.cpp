class Solution {
public:
    int compute(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = (nums[i] == target) ? 0 : 1;
        }
        int ops = 0;
        for (int i = 0; i < n - 1; i++) {
            if (b[i] == 1) {
                ops++;
                b[i] = 0;
                b[i + 1] = 1 - b[i + 1];
            }
        }
        const int INF = 1000000000;
        if (b[n - 1] == 1)
            return INF;
        return ops;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int prod = 1;
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
        }
        if (n % 2 == 0) {
            if (prod != 1)
                return false;
            int ops1 = compute(nums, 1);
            int opsn1 = compute(nums, -1);
            int best = min(ops1, opsn1);
            return best <= k;
        } else {
            int target = prod;
            int ops = compute(nums, target);
            return ops <= k;
        }
    }
};