class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int left = 0, right = 0;
        while (right < nums.size() - 1) {
            int furthest = 0;
            for (int i = left; i <= right; i++) {
                furthest = max(furthest, i + nums[i]);
            }
            left = right + 1;
            right = furthest;
            res++;
        }
        return res;
    }
};