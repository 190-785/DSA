class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        for (int i = 0; i < s.length() - 1; ++i) {
            char a = s[i];
            char b = s[i + 1];
            if (a != b && freq[a] == a - '0' && freq[b] == b - '0') {
                return string(1, a) + string(1, b);
            }
        }
        return "";
    }
};
