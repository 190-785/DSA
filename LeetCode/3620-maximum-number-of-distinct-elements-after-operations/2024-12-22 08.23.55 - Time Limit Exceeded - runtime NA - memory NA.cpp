class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<int> distinct;
        if (k == 0) {
            return set<int>(nums.begin(), nums.end()).size();
        }
        for (int num : nums) {
            for (int val = num - k; val <= num + k; ++val) {
                if (distinct.find(val) == distinct.end()) {
                    distinct.insert(val);
                    break;
                }
            }
        }
        return distinct.size();
    }
};
