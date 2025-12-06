class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        while (nums.size() >
               unordered_set<int>(nums.begin(), nums.end()).size()) {
            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
            operations++;
        }

        return operations;
    }
};
