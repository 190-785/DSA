class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> delta(n + 1, 0);
        for (const auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            for (int i = li; i <= ri; ++i) {
                if (nums[i] > 0) {
                    nums[i]--;
                }
            }
        }
        for (int num : nums) {
            if (num != 0)
                return false;
        }
        return true;
    }
};
