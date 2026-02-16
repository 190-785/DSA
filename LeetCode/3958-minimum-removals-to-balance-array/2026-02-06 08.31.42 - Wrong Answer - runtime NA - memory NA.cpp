class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2)
            return 0;
        int minElement = *min_element(nums.begin(), nums.end());
        int minRemoval = 0;
        long long kMinEl = k * minElement;
        for (int i = 0; i < n; i++) {
            if (nums[i] > kMinEl)
                minRemoval++;
        }
        return minRemoval;
    }
};