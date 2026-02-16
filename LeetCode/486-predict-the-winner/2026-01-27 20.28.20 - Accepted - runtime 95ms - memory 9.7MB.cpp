class Solution {
public:
    int choices(vector<int>& nums, int start, int end) {
        if (start == end)
            return nums[start];
        int startScore =
            nums[start] - choices(nums, start + 1, end);
        int endScore =  nums[end] - choices(nums, start, end - 1);
        return max( startScore, endScore);
    }
    bool predictTheWinner(vector<int>& nums) {
        /*
            sp1>=sp2
            (sp1-sp2)>=0

        */
        int n = nums.size();
        return (choices(nums, 0, n - 1) >= 0);
    }
};