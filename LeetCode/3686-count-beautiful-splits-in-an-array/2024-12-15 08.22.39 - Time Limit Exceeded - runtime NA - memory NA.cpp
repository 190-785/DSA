class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefix(nums, 0, i, i, j) || isPrefix(nums, i, j, j, n)) {
                    count++;
                }
            }
        }

        return count;
    }

    bool isPrefix(vector<int>& nums, int start1, int end1, int start2, int end2) {
        int len1 = end1 - start1, len2 = end2 - start2;
        if (len1 > len2) return false;

        for (int i = 0; i < len1; ++i) {
            if (nums[start1 + i] != nums[start2 + i]) {
                return false;
            }
        }

        return true;
    }
};
