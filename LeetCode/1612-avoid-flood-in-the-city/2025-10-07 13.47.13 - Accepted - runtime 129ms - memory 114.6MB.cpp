class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> last;
        set<int> zeroes;
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                zeroes.insert(i);
            } else {
                int lake = rains[i];
                auto itLast = last.find(lake);
                if (itLast != last.end()) {
                    auto it = zeroes.upper_bound(itLast->second);
                    if (it == zeroes.end())
                        return {};
                    ans[*it] = lake;
                    zeroes.erase(it);
                }
                last[lake] = i;
            }
        }
        for (int idx : zeroes)
            ans[idx] = 1;
        return ans;
    }
};
