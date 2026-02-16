class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<int> freqChar(26, 0);
        int n = pattern.size();
        for (int i = 0; i < n; i++) {
            freqChar[pattern[i] - 'a']++;
        }
        unordered_map<string, int> freqWord;
        int m = s.size();
        int i = 0;
        while (i < m) {
            int j = i;
            string curr = "";
            while (j < m && s[j] != ' ') {
                curr += s[j];
                j++;
            }
            freqWord[curr]++;
            i = j + 1;
        }
        for (auto it : freqWord) {
            bool found = false;
            for (int i = 0; i < 26; i++) {
                if (freqChar[i] == it.second) {
                    freqChar[i] = 0;
                    found = true;
                    it.second = -1;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
};