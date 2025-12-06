class Solution {
public:
    void f(vector<vector<int>>& res, vector<int>& candidates,
           vector<int>& subset, int idx, int target, int currentSum) {
        if (currentSum == target) {
            res.push_back(subset);
            return;
        }
        if (currentSum > target || idx >= candidates.size()) {
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            subset.push_back(candidates[i]);
            f(res, candidates, subset, i + 1, target,
              currentSum + candidates[i]);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        f(res, candidates, subset, 0, target, 0);
        return res;
    }
};
