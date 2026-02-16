class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            for (int pos = 0; pos <= nums[i]; pos++) {
                if ((nums[i]) == (pos | (pos + 1))) {
                    ans[i] = pos;
                    break;
                }
            }
        }
        return ans;
    }
};
