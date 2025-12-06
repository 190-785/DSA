class Solution {
public:
    void findComb(int idx, int target, vector<int>& arr,
                  vector<vector<int>>& res, vector<int>& ds) {
        // if (target == 0) {
        //     res.push_back(ds);
        //     return;
        // }
        if (idx == arr.size()) {
            if (target == 0) {
                res.push_back(ds);
            }
            return;
        }
        if (arr[idx] <= target) {
            ds.push_back(arr[idx]);
            findComb(idx, target - arr[idx], arr, res, ds);
            ds.pop_back();
        }
        findComb(idx + 1, target, arr, res, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        findComb(0, target, candidates, res, ds);
        return res;
    }
};