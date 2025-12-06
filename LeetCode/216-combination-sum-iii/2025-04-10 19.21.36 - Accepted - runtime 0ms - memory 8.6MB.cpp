class Solution {
public:
    void findComb(int idx, int n, int k, vector<int>& arr, vector<int>& ds,
                  vector<vector<int>>& res) {
        if (k == 0) {
            if (n == 0)
                res.push_back(ds);
            return;
        }
        if (idx >= arr.size())
            return;
        if (arr[idx] <= n) {
            ds.push_back(arr[idx]);
            findComb(idx + 1, n - arr[idx], k - 1, arr, ds, res);
            ds.pop_back();
        }
        findComb(idx + 1, n, k, arr, ds, res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> res;
        vector<int> subset;
        findComb(0, n, k, arr, subset, res);
        return res;
    }
};