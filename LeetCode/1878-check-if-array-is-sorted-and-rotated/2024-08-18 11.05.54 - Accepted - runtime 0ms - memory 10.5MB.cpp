class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
                // If more than one decreasing point is found, return false
                if (count > 1) return false;
            }
        }

        // If no decreasing points or only one is found, it's a valid rotation
        return true;
    }
};