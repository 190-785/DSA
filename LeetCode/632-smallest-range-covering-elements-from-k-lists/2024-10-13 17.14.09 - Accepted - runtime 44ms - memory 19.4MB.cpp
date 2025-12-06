class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            range;
        int curMax = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            range.push(make_tuple(nums[i][0], i, 0));
            curMax = max(curMax, nums[i][0]);
        }
        int bestStart = 0;
        int bestEnd = INT_MAX;
        while (true) {
            auto [curMin, row, col] = range.top();
            range.pop();

            if ((curMax - curMin) < (bestEnd-bestStart)) {
                bestStart = curMin;
                bestEnd = curMax;
            }
            if (col + 1 == nums[row].size()) {
                break;
            }
            range.push(make_tuple(nums[row][col + 1], row, col + 1));
            curMax = max(curMax, nums[row][col + 1]);
        }
        return {bestStart, bestEnd};
    }
};