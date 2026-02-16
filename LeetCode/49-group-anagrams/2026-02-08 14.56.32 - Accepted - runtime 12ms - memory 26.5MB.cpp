class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mpp;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            string currStr = strs[i];
            sort(currStr.begin(), currStr.end());
            mpp[currStr].push_back(i);
        }
        vector<vector<string>> res;
        for (auto it : mpp) {
            vector<string> curr;
            for (auto x : it.second) {
                curr.push_back(strs[x]);
            }
            res.push_back(curr);
        }
        return res;
    }
};