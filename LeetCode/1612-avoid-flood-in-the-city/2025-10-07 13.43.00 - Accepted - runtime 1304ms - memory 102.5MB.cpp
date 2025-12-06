class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> indices;
        vector<int> zeroes;
        vector<char> zeroUsed;
        //For to God I hope this not result in MLE
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                zeroes.push_back(i);
                zeroUsed.push_back(false);
            } else {
                auto it = indices.find(rains[i]);
                if (it != indices.end()) {
                    auto uIt =
                        upper_bound(zeroes.begin(), zeroes.end(), it->second);

                    if (uIt == zeroes.end())
                        return {};

                    while (uIt != zeroes.end() &&
                           zeroUsed[uIt - zeroes.begin()]) {
                        ++uIt;
                    }

                    if (uIt == zeroes.end())
                        return {};

                    int dayIndex = *uIt;
                    ans[dayIndex] = it->first;
                    zeroUsed[uIt - zeroes.begin()] = true;
                }
                indices[rains[i]] = i;
            }
        }

        for (int i = 0; i < (int)zeroes.size(); ++i) {
            if (!zeroUsed[i])
                ans[zeroes[i]] = 1;
        }
        return ans;
    }
};
