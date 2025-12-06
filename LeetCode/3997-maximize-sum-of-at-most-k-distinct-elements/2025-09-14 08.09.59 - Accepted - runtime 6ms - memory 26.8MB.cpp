class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> res;
        int last = nums[0];
        res.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (res.size() == k)
                break;
            if (res.back() != nums[i])
                res.push_back(nums[i]);
        }
        return res;
    }
};