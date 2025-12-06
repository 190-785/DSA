class Solution {
public:
    void f(vector<vector<int>>& res, vector<int>& candidates,
           vector<int>& subset, int idx, int target) {
        if (idx >= candidates.size()) {
            if (accumulate(subset.begin(), subset.end(), 0) == target) {
                res.push_back(subset);
            }
            return;
        }
        subset.push_back(candidates[idx]);
        f(res, candidates, subset, idx + 1, target);
        subset.pop_back();
        while (idx + 1 < candidates.size() &&
               candidates[idx] == candidates[idx + 1]) {
            ++idx;
        }
        f(res, candidates, subset, idx + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        f(res, candidates, subset, 0, target);
        return res;
    }
};