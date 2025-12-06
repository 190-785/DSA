class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char, int>> stk;
        for (char c : s) {
            if (stk.empty() || stk.back().first != c) {
                stk.push_back({c, 1});
            } else {
                stk.back().second++;
            }
            if (c == ')' && stk.size() >= 2) {
                auto [ch2, cnt2] = stk.back();
                stk.pop_back();
                auto [ch1, cnt1] = stk.back();
                stk.pop_back();
                if (ch1 == '(' && ch2 == ')' && cnt1 >= k && cnt2 >= k) {
                    cnt1 -= k;
                    cnt2 -= k;
                    if (cnt1 > 0)
                        stk.push_back({ch1, cnt1});
                    if (cnt2 > 0)
                        stk.push_back({ch2, cnt2});
                } else {
                    stk.push_back({ch1, cnt1});
                    stk.push_back({ch2, cnt2});
                }
            }
        }
        string res;
        for (auto [c, cnt] : stk)
            res.append(cnt, c);
        return res;
    }
};