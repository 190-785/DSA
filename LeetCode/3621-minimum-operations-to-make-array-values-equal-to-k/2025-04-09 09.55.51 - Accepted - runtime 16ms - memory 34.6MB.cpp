class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num : nums) {
            if (num < k)
                return -1;
        }

        sort(nums.rbegin(), nums.rend());
        int operations = 0;
        set<int> seen;

        for (int num : nums) {
            if (num > k && seen.find(num) == seen.end()) {
                operations++;
                seen.insert(num);
            }
        }

        return operations;
    }
};
