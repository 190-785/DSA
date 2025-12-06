class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> result;
        vector<int> left(26, 0), right(26, 0);
        
        for (char c : s) {
            right[c - 'a']++;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            right[s[i] - 'a']--;
            for (int j = 0; j < 26; ++j) {
                if (left[j] > 0 && right[j] > 0) {
                    result.insert(string(1, 'a' + j) + s[i] + string(1, 'a' + j));
                }
            }
            left[s[i] - 'a']++;
        }
        
        return result.size();
    }
};
