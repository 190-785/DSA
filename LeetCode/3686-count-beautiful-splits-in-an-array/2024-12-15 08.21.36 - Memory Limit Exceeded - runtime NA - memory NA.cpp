class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int> nums1(nums.begin(), nums.begin() + i);
                vector<int> nums2(nums.begin() + i, nums.begin() + j);
                vector<int> nums3(nums.begin() + j, nums.end());

                if (isPrefix(nums1, nums2) || isPrefix(nums2, nums3)) {
                    count++;
                }
            }
        }

        return count;
    }

    bool isPrefix(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return false;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
};
