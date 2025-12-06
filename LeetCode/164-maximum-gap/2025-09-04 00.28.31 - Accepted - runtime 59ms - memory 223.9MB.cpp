class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int maxEl = *max_element(nums.begin(), nums.end());
        int minEl = *min_element(nums.begin(), nums.end());

        if (maxEl - minEl > 1e6) {
            sort(nums.begin(), nums.end());
            int res = 0;
            for (int i = 1; i < nums.size(); ++i) {
                res = max(res, nums[i] - nums[i - 1]);
            }
            return res;
        }

        vector<bool> present(maxEl + 1, false);
        for (int num : nums) {
            present[num] = true;
        }

        int res = 0;
        int last = -1;
        for (int i = minEl; i <= maxEl; ++i) {
            if (present[i]) {
                if (last != -1) {
                    res = max(res, i - last);
                }
                last = i;
            }
        }

        return res;
    }
};
