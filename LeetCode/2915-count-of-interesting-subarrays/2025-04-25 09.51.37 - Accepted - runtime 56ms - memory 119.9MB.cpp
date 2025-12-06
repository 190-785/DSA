class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> prefixCount(n + 1, 0);
        unordered_map<int, int> freq;

        freq[0] = 1;
        long long result = 0;

        for (int i = 0; i < n; i++) {
            prefixCount[i + 1] =
                prefixCount[i] + ((nums[i] % modulo == k) ? 1 : 0);

            int target = (prefixCount[i + 1] - k + modulo) % modulo;
            if (freq.find(target) != freq.end()) {
                result += freq[target];
            }

            freq[prefixCount[i + 1] % modulo]++;
        }

        return result;
    }
};
