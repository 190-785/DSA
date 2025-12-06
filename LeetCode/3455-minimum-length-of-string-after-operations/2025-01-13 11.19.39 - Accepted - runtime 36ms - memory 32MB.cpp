class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            int n = s[i] - 'a';
            freq[n]++;
            if (freq[n] > 2) {
                freq[n] = freq[n] % 3 + 1;
            }
        }
        return accumulate(freq.begin(), freq.end(), 0);
    }
};