class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int possible_ans = 0; possible_ans <= nums[i]; possible_ans++) {
                if ((nums[i]) == (possible_ans | (possible_ans + 1))) {
                    ans[i] = possible_ans;
                    break;
                }
            }
        }
        return ans;
    }
};
