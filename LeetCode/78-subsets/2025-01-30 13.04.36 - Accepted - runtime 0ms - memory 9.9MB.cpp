class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        int n = nums.size();
        int sub = 1 << n;
        for (int i = 0; i < sub; i++) {
            vector<int> set;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    set.push_back(nums[j]);
            }
            sets.push_back(set);
        }
        return sets;
    }
};