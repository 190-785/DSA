class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        int maxVowelFreq = 0, maxConsonantFreq = 0;
        for (char ch : s) {
            freq[ch]++;
        }
        for (const auto& pair : freq) {
            char ch = pair.first;
            int count = pair.second;

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                maxVowelFreq = max(maxVowelFreq, count);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, count);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};