class Solution {
public:
    void perma(vector<int>& nums, vector<vector<int>>& res, int idx, int n) {
        if (idx == n) {
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < n; i++) {
            swap(nums[idx], nums[i]);
            perma(nums, res, idx + 1, n);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        perma(nums, res, 0, n);
        return res;
    }
};