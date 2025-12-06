class Solution {
public:
    long long count(vector<int>& nums, int k, int maxE) {
        long long res = 0;
        int left = 0, right = 0;
        int n = nums.size();
        int freq = 0;
        while (right < n) {
            if (nums[right] == maxE)
                freq++;
            while (freq >= k) {
                // For at least of some condition we use res+=(n-right)
                // Whereas for at most we use res+=(right-left)+1;
                res += (n - right);
                if (nums[left] == maxE)
                    freq--;
                left++;
            }
            right++;
        }
        return res;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(nums.begin(), nums.end());
        return count(nums, k, maxE);
    }
};