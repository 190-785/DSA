class Solution {
public:
    int count(vector<int>& nums, int distinct) {
        if (distinct < 0)
            return 0;
        int n = nums.size();
        int res = 0;
        int left = 0;
        unordered_map<int, int> subfreq;

        for (int right = 0; right < n; ++right) {
            subfreq[nums[right]]++;

            while ((int)subfreq.size() > distinct) {
                subfreq[nums[left]]--;
                if (subfreq[nums[left]] == 0)
                    subfreq.erase(nums[left]);
                left++;
            }

            res += (right - left + 1);
        }

        return res;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> freq(nums.begin(), nums.end());
        int totalDistinct = freq.size();
        return count(nums, totalDistinct) - count(nums, totalDistinct - 1);
    }
};
