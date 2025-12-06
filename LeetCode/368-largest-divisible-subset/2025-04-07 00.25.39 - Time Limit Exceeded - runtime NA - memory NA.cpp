class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result, temp;
        findSubset(0, nums, temp, -1, result);
        return result;
    }

private:
    void findSubset(int index, vector<int>& nums, vector<int>& temp, int prev, vector<int>& result) {
        if (temp.size() > result.size()) {
            result = temp;
        }
        
        for (int i = index; i < nums.size(); i++) {
            if (prev == -1 || nums[i] % prev == 0) {
                temp.push_back(nums[i]);
                findSubset(i + 1, nums, temp, nums[i], result);
                temp.pop_back();
            }
        }
    }
};
