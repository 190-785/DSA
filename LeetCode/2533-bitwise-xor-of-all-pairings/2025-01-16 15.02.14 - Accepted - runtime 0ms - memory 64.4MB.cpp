class Solution {
public:
    int xorOne(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        //Since if both are appearing even times they will cancel each ther out
        if (nums1.size() % 2 == 0 && nums2.size() % 2 == 0)
            return 0;
        if (nums1.size() % 2 == 0)
            return xorOne(nums1);
        if (nums2.size() % 2 == 0)
            return xorOne(nums2);
        return xorOne(nums1) ^ xorOne(nums2);
    }
};