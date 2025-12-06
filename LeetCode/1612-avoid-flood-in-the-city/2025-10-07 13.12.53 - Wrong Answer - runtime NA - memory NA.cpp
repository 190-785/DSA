class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> indices;
        vector<int> zeroes;
        int zer = 0;
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0)
                zeroes.push_back(i);
            else {
                auto it = indices.find(rains[i]);
                if (it != indices.end()) {
                    if (zer >= zeroes.size())
                        return {};
                    if(zeroes[zer]<it->second) return {};
                    ans[zeroes[zer]] = it->first;
                    zer++;
                }
                indices[rains[i]] = i;
            }
        }
        for (int i = zer; i < zeroes.size(); i++) {
            ans[zeroes[i]] = 1;
        }
        return ans;
    }
};