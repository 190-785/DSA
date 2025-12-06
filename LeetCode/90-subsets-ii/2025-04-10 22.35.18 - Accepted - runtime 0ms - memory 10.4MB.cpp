class Solution {
public:
    void findSubSet(int idx, vector<int>& nums, vector<int>& subset,
                    vector<vector<int>>& res) {
        res.push_back(subset);
        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i - 1])
                continue;
            subset.push_back(nums[i]);
            findSubSet(i + 1, nums, subset, res);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        findSubSet(0, nums, subset, res);
        return res;
    }
};