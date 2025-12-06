class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int maxFreq = 0;  
        for (int i = 0; i < n; ++i) {
            nums[i] -= k;
        }

        unordered_map<int, int> freq;  
        int left = 0;               

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;  
            int zeroFreq = freq[0];  
            int maxOtherFreq = 0;   
            for (auto [num, count] : freq) {
                if (num != 0) {
                    maxOtherFreq = max(maxOtherFreq, count);
                }
            }
            maxFreq = max(maxFreq, zeroFreq + maxOtherFreq);
        }

        return maxFreq;
    }
};
