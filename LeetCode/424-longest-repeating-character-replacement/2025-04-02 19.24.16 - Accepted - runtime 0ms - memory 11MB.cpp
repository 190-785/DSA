class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int n = s.size();
        int maxLen = 0;
        vector<int> freq(26, 0);
        int maxfreq = 0;
        while (r < n) {
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);
            while ((r - l + 1 - maxfreq) > k) {
                freq[s[l] - 'A']--;
                l++;
                maxfreq = 0;
                for (int i = 0; i < freq.size(); i++) {
                    maxfreq = max(maxfreq, freq[i]);
                }
            }
            if ((r - l + 1 - maxfreq) <= k)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};