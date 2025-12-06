class Solution {
public:
    void recPerma(int idx, vector<int>& nums, set<vector<int>>& perma) {
        if (idx == nums.size()) {
            perma.insert(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            recPerma(idx + 1, nums, perma);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> perma;
        recPerma(0, nums, perma);
        return vector<vector<int>>(perma.begin(), perma.end());
    }
};