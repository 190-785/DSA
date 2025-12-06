class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int n = s.size();
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        unordered_map<int, vector<char>> groups;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0)
                groups[cnt[i]].push_back('a' + i);
        }
        int maxSize = 0, maxK = 0;
        for (auto& g : groups) {
            int k = g.first;
            int sz = (int)g.second.size();
            if (sz > maxSize || (sz == maxSize && k > maxK)) {
                maxSize = sz;
                maxK = k;
            }
        }
        string res;
        if (maxSize == 0)
            return res;
        for (char c : groups[maxK])
            res.push_back(c);
        return res;
    }
};