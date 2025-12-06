class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                negative.push_back(nums[i]);
            } else {
                positive.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = positive[i / 2];
            } else {
                nums[i] = negative[i / 2];
            }
        }
        return nums;
    }
};