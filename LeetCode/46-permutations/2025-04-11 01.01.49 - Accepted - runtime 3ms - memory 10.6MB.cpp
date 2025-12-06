class Solution {
public:
    void recuPerma(vector<int>& perma, vector<int>& nums,
                   vector<vector<int>>& res, vector<int>& freq) {
        if (perma.size() == nums.size()) {
            res.push_back(perma);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                perma.push_back(nums[i]);
                freq[i] = 1;
                recuPerma(perma, nums, res, freq);
                freq[i] = 0;
                perma.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> freq(nums.size(), 0);
        vector<int> perma;
        recuPerma(perma, nums, res, freq);
        return res;
    }
};