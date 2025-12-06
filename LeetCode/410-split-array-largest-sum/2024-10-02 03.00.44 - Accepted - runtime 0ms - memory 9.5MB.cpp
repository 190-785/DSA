class Solution {
public:
    int countSubarrays(vector<int>& nums, int maxSum) {
        int subarrayCount = 1;
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                subarrayCount++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }
        return subarrayCount;
    }

    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int subarrayCount = countSubarrays(nums, mid);
            if (subarrayCount > k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};
