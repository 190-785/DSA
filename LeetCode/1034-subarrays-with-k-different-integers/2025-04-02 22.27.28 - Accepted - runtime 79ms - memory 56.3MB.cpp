class Solution {
public:
    int subK(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        unordered_map<int, int> freq;
        int l = 0, r = 0;
        int n = nums.size();
        int cnt = 0;
        while (r < n) {
            freq[nums[r]]++;
            while (freq.size() > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subK(nums, k) - subK(nums, k - 1);
    }
};