class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> best;
        int n = x.size();
        for (int i = 0; i < n; i++) {
            if (best.find(x[i]) == best.end() || y[i] > best[x[i]]) {
                best[x[i]] = y[i];
            }
        }
        vector<int> candidates;
        for (auto& it : best) {
            candidates.push_back(it.second);
        }
        if (candidates.size() < 3) {
            return -1;
        }
        sort(candidates.begin(), candidates.end(), greater<int>());
        return candidates[0] + candidates[1] + candidates[2];
    }
};