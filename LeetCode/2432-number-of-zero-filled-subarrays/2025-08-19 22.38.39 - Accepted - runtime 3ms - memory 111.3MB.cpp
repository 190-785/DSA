class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int start = -1, end = -1;
        // Formula to find the number of subarrays = N*(N+1)/2;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0 && start != -1) {
                long long length = end - start + 1;
                res += (length * (length + 1)) / 2;
                start = -1, end = -1;
            } else if (nums[i] == 0) {
                if (start == -1) {
                    start = i;
                }
                end = i;
            }
        }
        if (start != -1) {
            long long length = end - start + 1;
            res += (length * (length + 1)) / 2;
        }

        return res;
    }
};
