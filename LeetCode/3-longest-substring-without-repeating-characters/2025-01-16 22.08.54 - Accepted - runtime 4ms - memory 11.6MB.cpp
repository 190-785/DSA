class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> indexMap;
        int maxLength = 0;
        int start = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (indexMap.find(s[i]) != indexMap.end() && indexMap[s[i]] >= start) {
                start = indexMap[s[i]] + 1;
            }
            indexMap[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }
        
        return maxLength;
    }
};
