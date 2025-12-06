class Solution {
public:
    int minOperations(string s) {
        int res = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        int first = 0;
        for (int i = 1; i < 26; i++) {
            if (freq[i] != 0) {
                first = i;
                break;
            }
        }

        return (first == 0) ? 0 : 26 - first;
    }
};