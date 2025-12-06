class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int prev = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int curr = min(max(nums[i] - k, prev + 1), nums[i] + k);
            if (curr > prev) {
                res++;
                prev = curr;
            }
        }
        return res;
    }
};