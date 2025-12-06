class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxEl = *max_element(nums.begin(), nums.end());
        vector<int> sortedArr(maxEl + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sortedArr[nums[i]] = 1;
        }
        int res = 0;
        int last = -1;
        for (int i = 0; i <= maxEl; i++) {
            if (sortedArr[i] != 0) {
                if (last == -1) {
                    last = i;
                } else {
                    res = max(res, i - last);
                    last = i;
                }
            }
        }
        return res;
    }
};