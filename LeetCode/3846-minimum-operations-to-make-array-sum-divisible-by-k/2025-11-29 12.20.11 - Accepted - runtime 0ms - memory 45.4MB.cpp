class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long rem = 0;
        for (int x : nums) {
            rem = (rem + x) % k;
        }
        return static_cast<int>(rem);
    }
};
