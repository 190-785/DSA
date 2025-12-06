class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int i = 0, n = nums.size();
        while (i < n - 2) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    long long temp = (nums[i] - nums[j]) * nums[k];
                    res = max(res, temp);
                }
            }
            i++;
        }
        return res;
    }
};