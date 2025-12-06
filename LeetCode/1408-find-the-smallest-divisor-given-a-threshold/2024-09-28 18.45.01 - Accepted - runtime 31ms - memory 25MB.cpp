class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        while (start <= end) {
            long long sum = 0;
            int mid = start + (end - start) / 2;
            for (int i = 0; i < nums.size(); i++) {
                sum += (nums[i] + mid - 1) / mid;
                if (sum > threshold) {
                    break;
                }
            }
            if (sum > threshold) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};