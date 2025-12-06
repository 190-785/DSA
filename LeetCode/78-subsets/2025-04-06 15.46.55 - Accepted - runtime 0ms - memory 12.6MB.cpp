class Solution {
public:
    void f(vector<int>& subset, int idx, vector<vector<int>>& allSubsets,
           vector<int>& nums) {
        if (idx >= nums.size()) {
            allSubsets.push_back(subset);
            return;
        }
        f(subset, idx + 1, allSubsets, nums);
        subset.push_back(nums[idx]);
        f(subset, idx + 1, allSubsets, nums);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> subset;
        f(subset, 0, allSubsets, nums);
        return allSubsets;
    }
};