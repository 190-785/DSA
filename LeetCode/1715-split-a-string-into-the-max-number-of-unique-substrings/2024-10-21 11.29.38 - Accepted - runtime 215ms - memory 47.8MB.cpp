class Solution {
public:
    int backtrack(const string& s, int index, unordered_set<string>& used) {
        if (index == s.size()) {
            return 0;
        }
        int maxSplit = 0;
        string currentSubstring = "";

        for (int i = index; i < s.size(); ++i) {
            currentSubstring += s[i];
            if (used.find(currentSubstring) == used.end()) {
                used.insert(currentSubstring);
                int nextSplitCount = 1 + backtrack(s, i + 1, used);
                maxSplit = max(maxSplit, nextSplitCount);

                used.erase(currentSubstring);
            }
        }

        return maxSplit;
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string> used;
        return backtrack(s, 0, used);
    }
};
