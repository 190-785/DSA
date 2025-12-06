class Solution {
public:
    int count(vector<int>& nums, int distinct) {
        if (distinct < 0)
            return 0;
        int n = nums.size();
        int res = 0;
        int left = 0, right = 0;
        unordered_map<int, int> subfreq;
        while (right < n) {
            subfreq[nums[right]]++;
            while (subfreq.size() > distinct) {
                int num = nums[left];
                subfreq[num]--;
                if (subfreq[num] == 0) {
                    subfreq.erase(num);
                }
                left++;
            }
            res += (right - left + 1);
            right++;
        }
        return res;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> freq(nums.begin(), nums.end());
        return count(nums, freq.size()) - count(nums, freq.size() - 1);
    }
};