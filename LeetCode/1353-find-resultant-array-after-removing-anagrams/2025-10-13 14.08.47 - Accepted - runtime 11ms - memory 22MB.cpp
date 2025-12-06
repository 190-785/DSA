class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                freq[i][c - 'a']++;
            }
        }
        stack<pair<vector<int>, int>> stk;
        stk.push({freq[0], 0});
        int i = 1;
        while (!stk.empty() && i < n) {
            auto v1 = stk.top();
            bool isAna = true;
            for (int j = 0; j < 26; j++) {
                if (freq[i][j] != v1.first[j]) {
                    isAna = false;
                    break;
                }
            }
            if (!isAna) {
                stk.push({freq[i], i});
            }
            i++;
        }
        vector<string> res;
        while (!stk.empty()) {
            auto v1 = stk.top();
            int idx = v1.second;
            res.push_back(words[idx]);
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};