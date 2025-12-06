class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freqMap(101, 0);
        for (int num : nums) {
            freqMap[num]++;
        }

        int maxFreq = 0;
        for (int freq : freqMap) {
            maxFreq = max(maxFreq, freq);
        }

        int res = 0;
        for (int freq : freqMap) {
            if (freq == maxFreq) {
                res += freq;
            }
        }

        return res;
    }
};
