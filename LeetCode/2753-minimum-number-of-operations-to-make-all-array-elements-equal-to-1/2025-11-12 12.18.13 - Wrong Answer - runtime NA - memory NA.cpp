class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int countOne = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                countOne++;
        }
        if (countOne > 0)
            return n - countOne;
        int canOne = false;
        for (int i = 0; i < n - 1; i++) {
            if (std::gcd(nums[i], nums[i + 1]) == 1) {
                canOne = true;
                break;
            }
        }
        if (canOne)
            return n;
        return -1;
    }
};